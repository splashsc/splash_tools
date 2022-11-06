
void formDefineUserMgmt(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  websAspDefine("MakeGroupList",FUN_00410e3c,param_3,param_4,&_mips_gp0_value);
  websAspDefine("MakeUserList",FUN_00410d60);
  websAspDefine("MakeAccessLimitList",FUN_00410c84);
  websAspDefine("MakeAccessMethodList",FUN_0040fa24);
  websAspDefine("MakePrivilegeList",&LAB_0040f940);
  websFormDefine("AddUser",FUN_004109ac);
  websFormDefine("DeleteUser",FUN_00410804);
  websFormDefine("DisplayUser",FUN_00410620);
  websFormDefine("AddGroup",FUN_004102e0);
  websFormDefine("DeleteGroup",FUN_0041010c);
  websFormDefine("AddAccessLimit",FUN_0040fe80);
  websFormDefine("DeleteAccessLimit",FUN_0040fd34);
  websFormDefine("SaveUserManagement",FUN_0040fc20);
  websFormDefine("LoadUserManagement",FUN_0040fb0c);
  return;
}

