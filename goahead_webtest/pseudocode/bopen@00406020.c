
undefined4 bopen(int param_1,int param_2,uint param_3)

{
  int iVar1;
  
  iVar1 = DAT_00430b40;
  DAT_00430b40 = DAT_00430b40 + 1;
  DAT_00430050 = param_3;
  if (DAT_00430b40 < 2) {
    DAT_00430050 = param_3 | 2;
    if (param_1 == 0) {
      if (param_2 == 0) {
        param_2 = 0x10000;
      }
      DAT_00430050 = param_3;
      param_1 = (*(code *)PTR_malloc_00430a84)(param_2);
      if (param_1 == 0) {
        DAT_00430b40 = iVar1;
        return 0xffffffff;
      }
    }
    DAT_00430b44 = param_2;
    DAT_00430b48 = param_2;
    DAT_00430b4c = param_1;
    DAT_00430b50 = param_1;
    (*(code *)PTR_memset_004309cc)(&DAT_00430b54,0,0x34);
  }
  return 0;
}

