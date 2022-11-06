
void umCommit(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  
  puVar1 = &_mips_gp0_value;
  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {
    if (DAT_00430c54 != 0) {
      bfree();
    }
    DAT_00430c54 = bstrdup(param_1);
  }
  trace(3,"UM: Writing User Configuration to file <%s>\n",DAT_00430c54,param_4,puVar1);
  dbSave(DAT_004304f8,DAT_00430c54,0);
  return;
}

