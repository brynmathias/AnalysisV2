
class LatexRow(object):
    def __init__(self, fields):
        self._fields = fields
    def render(self, cols):
        fields = []
        for c in cols:
            if c[0] in self._fields and self._fields[c[0]] is not None:
                fields.append(str(self._fields[c[0]]))
            else:
                fields.append("")
        return " & ".join(fields) + "\\\\"

class LatexHLine(object):
    def __init__(self):
        pass
    def render(self, cols):
        return "\\hline"

class LatexHeader(object):
    def render(self, cols):
        return ("\\begin{table}\\begin{tabular}{|%s|}\n" % "|".join([c[2] for c in cols])+
                "\\hline\n"+
                " & ".join([c[1] for c in cols])+"\\\\\hline")

class LatexFooter(object):
    def render(self, cols):
        return "\\hline\\end{tabular}\\end{table}"

class Table(object):
    def __init__(self):
        self._rows = []
        self._cols = []
        self._table_header = LatexHeader()
        self._table_footer = LatexFooter()

    def addColumn(self, name, title, align = "c"):
        self._cols.append((name, title, align))
    def defineColumns(self, desc):
        for c in desc:
            self.addColumn(*c)
    def addRowFields(self, **kwargs):
        row = self.getDefaultRow()
        for k, v in kwargs.iteritems():
            if k in row:
                row[k] = v
            else: raise IndexError("Column %s does not exist" % k)
        self.addRow(row)

    def addRow(self, row):
        self._rows.append(LatexRow(row))
    def addHLine(self):
        self._rows.append(LatexHLine())
    def getDefaultRow(self):
        d = {}
        for c in self._cols:
            d[c[0]] = None
        return d
    def render(self):
        elements = [self._table_header] + self._rows + [self._table_footer]
        return ("\n".join([r.render(self._cols) for r in elements]))
