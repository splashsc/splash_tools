
void FUN_00412aa0(int *param_1)

{
  undefined4 uVar1;
  
  if (param_1[0x2d] != 0) {
    bfree();
  }
  if (param_1[0x2e] != 0) {
    bfree();
  }
  if (param_1[0x2f] != 0) {
    bfree();
  }
  if (param_1[0x30] != 0) {
    bfree();
  }
  if (param_1[0x31] != 0) {
    bfree();
  }
  if (param_1[0x3b] != 0) {
    bfree();
  }
  if (param_1[0x32] != 0) {
    bfree();
  }
  if (param_1[0x33] != 0) {
    bfree();
  }
  if (param_1[0x34] != 0) {
    bfree();
  }
  if (param_1[0x35] != 0) {
    bfree();
  }
  if (param_1[0x36] != 0) {
    bfree();
  }
  if (param_1[0x37] != 0) {
    bfree();
  }
  if (param_1[0x2c] != 0) {
    bfree();
  }
  if (param_1[0x39] != 0) {
    bfree();
  }
  if (param_1[0x3a] != 0) {
    bfree();
  }
  if (param_1[0x45] != 0) {
    bfree();
  }
  if (param_1[0x38] != 0) {
    bfree();
  }
  if (param_1[0x4a] != 0) {
    bfree();
  }
  if (param_1[0x4d] != 0) {
    bfree();
  }
  if (param_1[0x4c] != 0) {
    bfree();
  }
  if (param_1[0x4e] != 0) {
    bfree();
  }
  if (param_1[0x4b] != 0) {
    bfree();
  }
  if (param_1[0x4f] != 0) {
    bfree();
  }
  if (param_1[0x50] != 0) {
    bfree();
  }
  if (param_1[0x51] != 0) {
    bfree();
  }
  symClose(param_1[8]);
  if (*param_1 != 0) {
    ringqClose(param_1);
  }
  if (param_1[0x43] != 0) {
    uVar1 = hFree(PTR_webs_00430854);
    *(undefined4 *)PTR_websMax_00430858 = uVar1;
  }
  bfree(param_1);
  return;
}

