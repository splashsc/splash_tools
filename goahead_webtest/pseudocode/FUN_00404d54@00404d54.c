
undefined4 FUN_00404d54(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_10;
  undefined4 local_c;
  
  iVar1 = ejArgs(param_3,param_4,"%s %s",&local_c,&local_10);
  if (iVar1 < 2) {
    websError(param_2,400,"Insufficient args\n");
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = websWrite(param_2,"Name: %s, Address %s",local_c,local_10);
  }
  return uVar2;
}

