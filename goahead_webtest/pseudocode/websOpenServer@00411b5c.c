
int websOpenServer(int param_1,int param_2)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int local_30;
  int local_2c;
  undefined *local_28;
  undefined2 local_24;
  
  if (DAT_00430c18 == 0) {
    DAT_00430c18 = DAT_00430c18 + 1;
    websDefaultOpen();
    *(undefined4 *)PTR_webs_00430854 = 0;
    *(undefined4 *)PTR_websMax_00430858 = 0;
    uVar3 = symOpen(0x100);
    piVar5 = (int *)PTR_websMimeList_00430860;
    puVar1 = PTR_websMime_0043085c;
    *(undefined4 *)PTR_websMime_0043085c = uVar3;
    while( true ) {
      if (*piVar5 == 0) break;
      iVar4 = piVar5[1];
      uVar3 = *(undefined4 *)puVar1;
      valueString(&local_30,*piVar5,0);
      symEnter(uVar3,iVar4,local_30,local_2c,local_28,local_24,0);
      piVar5 = piVar5 + 2;
    }
    iVar4 = websUrlHandlerOpen();
    iVar2 = -1;
    if (-1 < iVar4) {
      websFormOpen();
      DAT_00430c1c = (*(code *)PTR_open_00430958)(s_log_txt_004300b0,0x309,0x1b6);
      DAT_00430c20 = (*(code *)PTR_open_00430958)(s_trace_txt_004300f0,0x309,0x1b6);
      traceSetHandler(FUN_00411904);
      local_28 = &_mips_gp0_value;
      iVar4 = 0;
      do {
        local_2c = iVar4 + param_1;
        if (param_2 < iVar4) {
          local_2c = local_2c + -1;
          local_30 = param_1;
          error("../webs.c",0xf7,3,"Couldn\'t open a socket on ports %d - %d");
          return -1;
        }
        DAT_00430c24 = socketOpenConnection(0,local_2c,FUN_0041289c,0);
        uVar3 = DAT_00430c14;
        iVar4 = iVar4 + 1;
      } while (DAT_00430c24 < 0);
      **(int **)(local_28 + -0x7d50) = local_2c;
      bfreeSafe(uVar3);
      bfreeSafe(DAT_00430c10);
      DAT_00430c14 = 0;
      DAT_00430c10 = 0;
      if (local_2c == 0x50) {
        DAT_00430c14 = bstrdup(*(undefined4 *)(local_28 + -0x7d4c));
        DAT_00430c10 = bstrdup(*(undefined4 *)(local_28 + -0x7d48));
      }
      else {
        local_30 = local_2c;
        fmtAlloc(&DAT_00430c14,0x850,"%s:%d",*(undefined4 *)(local_28 + -0x7d4c));
        local_30 = local_2c;
        fmtAlloc(&DAT_00430c10,0x850,"%s:%d",*(undefined4 *)(local_28 + -0x7d48));
      }
      trace(0,"webs: Listening for HTTP requests at address %s\n",DAT_00430c10);
      return local_2c;
    }
  }
  else {
    iVar2 = *(int *)PTR_websPort_00430840;
    DAT_00430c18 = DAT_00430c18 + 1;
  }
  return iVar2;
}

