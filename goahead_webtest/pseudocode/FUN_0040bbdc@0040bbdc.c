
uint FUN_0040bbdc(int *param_1,uint param_2,char *param_3,uint **param_4,uint param_5)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint **ppuVar4;
  uint uVar5;
  uint *puVar6;
  char *pcVar7;
  undefined4 uVar8;
  bool bVar9;
  uint *puVar10;
  uint *puVar11;
  undefined *puVar12;
  int local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  undefined4 local_38;
  uint **local_30;
  
  local_48 = *param_1;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  if ((local_48 == 0) || (uVar2 = param_2, param_5 != 0)) {
    local_38 = 1;
    if (param_5 != 0) {
      local_44 = param_5 & (int)~param_5 >> 0x1f;
    }
    uVar2 = local_44;
    local_40 = param_2;
    if ((local_48 != 0) && (param_5 != 0)) {
      local_30 = param_4;
      local_3c = (*(code *)PTR_strlen_0043095c)();
      param_4 = local_30;
      uVar2 = local_44;
    }
  }
  do {
    while( true ) {
      local_44 = uVar2;
      iVar3 = (int)*param_3;
      if (iVar3 == 0) {
        if (local_48 == 0) {
          FUN_0040b770(&local_48,0);
        }
        iVar3 = *param_1;
        if ((iVar3 == 0) || (param_5 != 0)) {
          *param_1 = local_48;
          iVar3 = *param_1;
        }
        if ((iVar3 != 0) && (0 < (int)param_2)) {
          if ((int)local_3c < (int)param_2) {
            *(undefined *)(iVar3 + local_3c) = 0;
          }
          else {
            *(undefined *)(iVar3 + local_44 + -1) = 0;
          }
        }
        if (param_5 != 0) {
          local_3c = local_44;
        }
        return local_3c;
      }
      uVar5 = 0;
      ppuVar4 = param_4;
      if (iVar3 == 0x25) break;
      param_3 = param_3 + 1;
LAB_0040c11c:
      local_30 = ppuVar4;
      FUN_0040b770(&local_48,iVar3);
      param_4 = local_30;
      uVar2 = local_44;
    }
    iVar3 = (int)param_3[1];
    param_3 = param_3 + 2;
    if (iVar3 == 0x25) goto LAB_0040c11c;
    while (iVar3 != 0) {
      if (iVar3 == 0x2d) {
        uVar5 = uVar5 | 1;
      }
      else if (iVar3 == 0x2b) {
        uVar5 = uVar5 | 2;
      }
      else if (iVar3 == 0x20) {
        uVar5 = uVar5 | 4;
      }
      else if (iVar3 == 0x23) {
        uVar5 = uVar5 | 8;
      }
      else {
        if (iVar3 != 0x30) {
          if (iVar3 == 0x2a) {
            puVar10 = *param_4;
            param_4 = param_4 + 1;
            if ((int)puVar10 < 0) {
              uVar5 = uVar5 | 1;
              puVar10 = (uint *)-(int)puVar10;
            }
            iVar3 = (int)*param_3;
            param_3 = param_3 + 1;
            goto LAB_0040bdc4;
          }
          break;
        }
        uVar5 = uVar5 | 0x10;
      }
      cVar1 = *param_3;
      param_3 = param_3 + 1;
      iVar3 = (int)cVar1;
    }
    puVar10 = (uint *)0x0;
    while ((*(ushort *)(*(int *)PTR___ctype_b_00430aa4 + iVar3 * 2) & 8) != 0) {
      puVar10 = (uint *)((int)puVar10 * 10 + iVar3 + -0x30);
      iVar3 = (int)*param_3;
      param_3 = param_3 + 1;
    }
LAB_0040bdc4:
    puVar11 = (uint *)0xffffffff;
    ppuVar4 = param_4;
    if (iVar3 == 0x2e) {
      uVar5 = uVar5 & 0xffffffef;
      iVar3 = (int)*param_3;
      if (iVar3 == 0x2a) {
        puVar11 = *param_4;
        iVar3 = (int)param_3[1];
        ppuVar4 = param_4 + 1;
        param_3 = param_3 + 2;
      }
      else {
        puVar11 = (uint *)0x0;
        while( true ) {
          param_3 = param_3 + 1;
          if ((*(ushort *)(*(int *)PTR___ctype_b_00430aa4 + iVar3 * 2) & 8) == 0) break;
          puVar11 = (uint *)((int)puVar11 * 10 + iVar3 + -0x30);
          iVar3 = (int)*param_3;
        }
      }
    }
    if (iVar3 == 0x68) {
      uVar2 = 0x20;
LAB_0040be64:
      uVar5 = uVar5 | uVar2;
      iVar3 = (int)*param_3;
      param_3 = param_3 + 1;
    }
    else if (iVar3 == 0x6c) {
      uVar2 = 0x40;
      goto LAB_0040be64;
    }
    if ((iVar3 == 100) || (iVar3 == 0x69)) {
      if ((uVar5 & 0x20) == 0) {
        puVar6 = *ppuVar4;
      }
      else {
        puVar6 = (uint *)(int)*(short *)ppuVar4;
      }
      if ((int)puVar6 < 0) {
        puVar12 = &DAT_0041dfb8;
        puVar6 = (uint *)-(int)puVar6;
      }
      else if ((uVar5 & 2) == 0) {
        if ((uVar5 & 4) == 0) {
LAB_0040bf98:
          puVar12 = (undefined *)0x0;
        }
        else {
          puVar12 = &DAT_0041d840;
        }
      }
      else {
        puVar12 = &DAT_0041dfb4;
      }
      uVar8 = 10;
LAB_0040bf74:
      bVar9 = false;
LAB_0040bf78:
      FUN_0040b990(&local_48,puVar6,uVar8,bVar9,puVar12,puVar10,puVar11,uVar5);
LAB_0040bf84:
      param_4 = ppuVar4 + 1;
      uVar2 = local_44;
    }
    else {
      if ((iVar3 == 0x6f) || (((iVar3 == 0x75 || (iVar3 == 0x78)) || (iVar3 == 0x58)))) {
        if ((uVar5 & 0x20) == 0) {
          puVar6 = *ppuVar4;
        }
        else {
          puVar6 = (uint *)(uint)*(ushort *)ppuVar4;
        }
        if (iVar3 == 0x6f) {
          if (((uVar5 & 8) == 0) || (puVar6 == (uint *)0x0)) {
            puVar12 = (undefined *)0x0;
          }
          else {
            puVar12 = &DAT_0041dfbc;
          }
          uVar8 = 8;
          goto LAB_0040bf74;
        }
        if (iVar3 == 0x75) goto LAB_0040bf98;
        if (((uVar5 & 8) == 0) || (puVar6 == (uint *)0x0)) {
          puVar12 = (undefined *)0x0;
          uVar8 = 0x10;
          bVar9 = iVar3 == 0x58;
        }
        else {
          if (iVar3 == 0x78) goto LAB_0040c0cc;
          puVar12 = &DAT_0041dfc4;
          uVar8 = 0x10;
          bVar9 = true;
        }
        goto LAB_0040bf78;
      }
      if (iVar3 == 99) {
        FUN_0040b770(&local_48,(int)*(char *)ppuVar4);
        goto LAB_0040bf84;
      }
      if ((iVar3 == 0x73) || (iVar3 == 0x53)) {
        pcVar7 = (char *)*ppuVar4;
        if ((uint *)pcVar7 == (uint *)0x0) {
          pcVar7 = "(null)";
LAB_0040c0a4:
          iVar3 = -1;
        }
        else {
          if ((uVar5 & 8) == 0) goto LAB_0040c0a4;
          iVar3 = (int)*pcVar7;
          pcVar7 = (char *)((int)pcVar7 + 1);
        }
        FUN_0040b85c(&local_48,pcVar7,iVar3,puVar10,puVar11,uVar5);
        goto LAB_0040bf84;
      }
      if (iVar3 == 0x70) {
        puVar6 = *ppuVar4;
LAB_0040c0cc:
        puVar12 = &DAT_0041dfc0;
        uVar8 = 0x10;
        goto LAB_0040bf74;
      }
      if (iVar3 != 0x6e) goto LAB_0040c11c;
      param_4 = ppuVar4 + 1;
      uVar2 = local_44;
      if ((uVar5 & 0x20) == 0) {
        **ppuVar4 = local_3c;
      }
      else {
        *(short *)*ppuVar4 = (short)local_3c;
      }
    }
  } while( true );
}

