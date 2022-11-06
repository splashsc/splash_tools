
undefined4
FUN_00403dac(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            char *param_5)

{
  int iVar1;
  
  if ((*param_5 != '\0') &&
     (iVar1 = (*(code *)PTR_strcmp_004309b4)(param_5,"/",param_3,param_4,&_mips_gp0_value),
     iVar1 != 0)) {
    return 0;
  }
  websRedirect(param_1,"/rssui/default_redirect.asp");
  return 1;
}

