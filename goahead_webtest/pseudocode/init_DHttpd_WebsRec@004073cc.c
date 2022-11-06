
void init_DHttpd_WebsRec(int param_1,undefined4 *param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (DAT_00430060 == 0xffffffff) {
    iVar2 = (*(code *)PTR_dxmlGetInt_00430a40)("/sys/defaultbypasslogin");
    DAT_00430060 = (uint)(iVar2 != 0);
  }
  *param_2 = DAT_00430ba0;
  param_2[2] = *(undefined4 *)(param_1 + 0xb8);
  param_2[3] = *(undefined4 *)(param_1 + 0xd8);
  param_2[1] = param_1 + 0x30;
  param_2[4] = *(undefined4 *)(param_1 + 0xec);
  uVar3 = *(undefined4 *)(param_1 + 0x110);
  param_2[6] = 0;
  param_2[5] = uVar3;
  uVar1 = DAT_00430060;
  param_2[8] = 0;
  param_2[7] = uVar1;
  param_2[9] = 0;
  param_2[10] = 0;
  param_2[0xb] = 0;
  return;
}

