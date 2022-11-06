
void websRedirect(undefined4 param_1,char *param_2)

{
  char cVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 uVar4;
  char *local_18;
  undefined4 local_14 [2];
  
  puVar2 = PTR_strstr_00430a14;
  local_18 = (char *)0x0;
  *(int *)(PTR_websStats_00430694 + 4) = *(int *)(PTR_websStats_00430694 + 4) + 1;
  local_14[0] = 0;
  iVar3 = (*(code *)puVar2)(param_2,&DAT_0041ee4c);
  if (iVar3 == 0) {
    cVar1 = *param_2;
    uVar4 = websGetVar(param_1,"HTTP_HOST",DAT_00430c14);
    fmtAlloc(&local_18,0x850,"http://%s/%s",uVar4,param_2 + (cVar1 == '/'));
    param_2 = local_18;
  }
  fmtAlloc(local_14,0x850,
           "<html><head></head><body>\r\n\t\tThis document has moved to a new <a href=\"%s\">location</a>.\r\n\t\tPlease update your documents to reflect the new location.\r\n\t\t</body></html>\r\n"
           ,param_2);
  FUN_00413894(param_1,0x12e,local_14[0],param_2);
  bfreeSafe(local_14[0]);
  bfreeSafe(local_18);
  return;
}

