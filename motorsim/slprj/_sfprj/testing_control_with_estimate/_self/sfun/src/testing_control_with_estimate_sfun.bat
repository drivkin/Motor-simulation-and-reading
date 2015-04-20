call "%VS100COMNTOOLS%\..\..\VC\vcvarsall.bat" AMD64
nmake -f testing_control_with_estimate_sfun.mak
