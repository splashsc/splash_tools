
int websAspRequest(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  char cVar8;
  char *pcVar9;
  int iVar10;
  char *pcVar11;
  int local_40;
  int local_3c [3];
  int local_30;
  
  *(uint *)(param_1 + 0x100) = *(uint *)(param_1 + 0x100) | 0x40000;
  uVar1 = websGetRequestPath();
  iVar2 = ejOpenEngine(*(undefined4 *)(param_1 + 0x20),DAT_00430040);
  if (iVar2 < 0) {
    websError(param_1,200,"Can\'t create Ejscript engine");
  }
  else {
    ejSetUserHandle(iVar2,param_1);
    iVar10 = websPageStat(param_1,param_2,uVar1,local_3c);
    if (-1 < iVar10) {
      iVar10 = balloc(local_3c[0] + 1);
      if (iVar10 == 0) {
        websError(param_1,200,"Can\'t get memory");
      }
      else {
        *(undefined *)(iVar10 + local_3c[0]) = 0;
        local_30 = websPageReadData(param_1,iVar10,local_3c[0]);
        if (local_30 == local_3c[0]) {
          websPageClose(param_1);
          pcVar11 = (char *)ballocAscToUni(iVar10,local_30);
          pcVar9 = pcVar11;
          if (pcVar11 == (char *)0x0) {
            websError(param_1,200,"Can\'t get memory");
          }
          else {
LAB_00405e44:
            if ((*pcVar9 == '\0') ||
               (iVar7 = (*(code *)PTR_strstr_00430a14)(pcVar9,&DAT_0041d934), iVar7 == 0)) {
              iVar7 = 0;
LAB_00405e74:
              if (((pcVar9 == (char *)0x0) || (*pcVar9 == '\0')) || (iVar7 != 0)) {
                local_30 = 0;
              }
              else {
                local_30 = iVar7;
                uVar1 = (*(code *)PTR_strlen_0043095c)(pcVar9);
                websWriteBlock(param_1,pcVar9,uVar1);
              }
              goto LAB_00405ed4;
            }
            websWriteBlock(param_1,pcVar9,iVar7 - (int)pcVar9);
            iVar7 = FUN_004057c0(iVar7 + 2);
            iVar3 = FUN_00405810(iVar7,"language");
            if ((iVar3 != 0) && (iVar3 = FUN_00405810(iVar3,"=javascript"), iVar3 != 0)) {
              iVar7 = iVar3;
            }
            puVar4 = (undefined *)(*(code *)PTR_strstr_00430a14)(iVar7,&DAT_0041d8b0);
            if (puVar4 != (undefined *)0x0) {
              *puVar4 = 0;
              pcVar9 = puVar4 + 2;
              pcVar5 = (char *)FUN_004057c0(iVar7);
              pcVar6 = pcVar5;
              do {
                cVar8 = *pcVar6;
                while( true ) {
                  if (cVar8 == '\0') {
                    if (*pcVar5 == '\0') goto LAB_00405e44;
                    local_40 = 0;
                    iVar7 = scriptEval(2,pcVar5,&local_40,iVar2);
                    if (-1 < iVar7) {
                      if (iVar7 != 0) goto LAB_00405e74;
                      goto LAB_00405e44;
                    }
                    local_30 = iVar7;
                    iVar7 = websValid(param_1);
                    if (iVar7 != 0) {
                      if (local_40 == 0) {
                        websWrite(param_1,"<h2><b>ASP Error</b></h2>\n%s\n",pcVar5);
                      }
                      else {
                        websWrite(param_1,"<h2><b>ASP Error: %s</b></h2>\n");
                        websWrite(param_1,"<pre>%s</pre>",pcVar5);
                        bfree(local_40);
                      }
                      websWrite(param_1,"</body></html>\n");
                      local_30 = 0;
                    }
                    goto LAB_00405ed4;
                  }
                  if ((cVar8 != '\\') || ((pcVar6[1] != '\r' && (pcVar6[1] != '\n')))) break;
                  do {
                    do {
                      *pcVar6 = ' ';
                      pcVar6 = pcVar6 + 1;
                      cVar8 = *pcVar6;
                    } while (cVar8 == '\r');
                  } while (cVar8 == '\n');
                }
                pcVar6 = pcVar6 + 1;
              } while( true );
            }
            websError(param_1,200,"Unterminated script in %s: \n",param_2);
          }
          local_30 = -1;
          goto LAB_00405ed4;
        }
        websError(param_1,200,"Cant read %s",param_2);
      }
      local_30 = -1;
      pcVar11 = (char *)0x0;
      goto LAB_00405ed4;
    }
    websError(param_1,0x194,"Can\'t stat %s",param_2);
  }
  local_30 = -1;
  pcVar11 = (char *)0x0;
  iVar10 = 0;
LAB_00405ed4:
  iVar7 = websValid(param_1);
  if ((iVar7 != 0) && (websPageClose(param_1), -1 < iVar2)) {
    ejCloseEngine(iVar2);
  }
  bfreeSafe(pcVar11);
  bfreeSafe(iVar10);
  return local_30;
}

