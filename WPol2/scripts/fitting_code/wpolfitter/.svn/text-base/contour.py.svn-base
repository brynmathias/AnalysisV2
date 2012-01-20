import ROOT as r
import wpolfitter.utils as utils
import os.path

def plot_contour(fit_globals, fit, contour_plane, out_file):
    c = r.TCanvas("contour")
    contour = r.RooPlot(fit_globals["f1"], fit_globals["f2"])
    fit["result"].plotOn(contour, fit_globals["f1"], fit_globals["f2"], "ME12VHB")
    mcontour = fit["minuit"].contour(fit_globals["f1"], fit_globals["f2"], 1, 2)
    mcontour.Draw()
    contour.Draw("SAME")
    if contour_plane == 0:
        c.SaveAs(out_file)
        return (out_file, [])
    contour_name = "contour_%s" % fit["nll"].GetName()
    ncontour = gross_transform(mcontour,
                               contour_plane -1,
                               contour_name,
                               2)
    ncontour.Draw();
    utils.ensure_dir(out_file)
    c.SaveAs(out_file)

def transform_contour(contour, mode , cont_name, n):
    from array import array
    g = contour.findObject("%s_n%d.000000" % (cont_name,n))
    if type(g).__name__ != "TGraph":
        return None
    g_N = g.GetN()
    ix1 = array("d")
    ix2 = array("d")
    iy1prime = array("d")
    iy2prime = array("d")
    iz1prime = array("d")
    iz2prime = array("d")
    idiff1 = array("d")
    isum1 = array("d")
    idiff2 = array("d")
    isum2 = array("d")
    for i in range(g_N):
        ix1.append(g.GetX()[i]);
        iy1prime.append((1.-(g.GetX()[i]))*(g.GetY()[i]))
        iz1prime.append((1.-(g.GetX()[i]))*(1.-(g.GetY()[i])))
        idiff1.append(ix1[i]-iy1prime[i])
        isum1.append(ix1[i]+iy1prime[i])
    if mode==1:
        c = r.TGraph(g_N,ix1,iy1prime);
    elif mode==0:
        c = r.TGraph(g_N,idiff1,isum1);
    elif mode==2:
        c = r.TGraph(g_N,ix1,iz1prime);
    elif mode==3:
        c = r.TGraph(g_N,iy1prime,iz1prime);
    c.SetLineStyle(n)
    c.SetLineWidth(2) ;
    c.SetLineColor(r.kBlue) ;
    return c

def gross_transform(contour, mode, cont_name, max_n):
    from array import array
    h = None
    if mode==0:
        h = r.RooPlot(-1.0, 1.0, 0, 1.0)
    else:
        h = r.RooPlot(0.,1.,0.,1.)

    point = contour.findObject("TMarker")

    contours = []
    for i in range(1, max_n+1):
        c = transform_contour(contour, mode, cont_name, i)
        if c is not None:
            contours.append(c)
            h.addObject(c, "L")
    mx=point.GetX();
    my=(1-point.GetX())*point.GetY();
    mz=(1-point.GetX())*(1.-point.GetY());
    dpoint = None
    if mode==1:
        dpoint=r.TMarker(mx,my,8);
        h.SetTitle(";f_{L};f_{R}");
    elif mode==0:
        dpoint=r.TMarker((mx-my),(mx+my),8);
        h.SetTitle(";f_{L}-f_{R};f_{L}+f_{R}");
    elif mode==2:
        dpoint=r.TMarker(mx,mz,8);
        h.SetTitle(";f_{L};f_{0}");
    elif mode==3:
        dpoint=r.TMarker(my,mz,8);
        h.SetTitle(";f_{R};f_{0}");
    h.addObject(dpoint);
    return h
