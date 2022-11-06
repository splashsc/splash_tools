
undefined4 socketOpen(void)

{
  DAT_00430bc0 = DAT_00430bc0 + 1;
  if (DAT_00430bc0 < 2) {
    *(undefined4 *)PTR_socketList_0043076c = 0;
    *(undefined4 *)PTR_socketMax_00430768 = 0;
    *(undefined4 *)PTR_socketHighestFd_004307a4 = 0xffffffff;
  }
  return 0;
}

