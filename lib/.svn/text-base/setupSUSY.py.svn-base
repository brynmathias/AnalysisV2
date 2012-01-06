import sys
if sys.version_info < (2, 6):
    import dl
    sys.setdlopenflags(dl.RTLD_NOW|dl.RTLD_GLOBAL)
else:
    import ctypes
    flags=sys.getdlopenflags()
    sys.setdlopenflags(flags|ctypes.RTLD_GLOBAL)

import os
import os.path

root_dir=os.environ.get("SUSY_WORKING_SW_DIR")+"/"
for d in os.listdir(root_dir):
    if os.path.isdir(root_dir+d) and os.path.exists(root_dir+d+"/python"):
        sys.path.append(root_dir+d+"/python")
