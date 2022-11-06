
/* WARNING: Removing unreachable block (ram,0x0040da64) */

int socketSelect(uint param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  int local_40;
  int local_3c;
  int local_38;
  int *local_34;
  int *local_30;
  int local_2c;
  
  iVar10 = (*(int *)PTR_socketHighestFd_004307a4 + 0x20U >> 5) << 2;
  iVar2 = balloc(iVar10);
  (*(code *)PTR_memset_004309cc)(iVar2,0,iVar10);
  iVar3 = balloc(iVar10);
  (*(code *)PTR_memset_004309cc)(iVar3,0,iVar10);
  iVar4 = balloc(iVar10);
  (*(code *)PTR_memset_004309cc)(iVar4,0,iVar10);
  local_40 = param_2 / 1000;
  local_3c = (param_2 % 1000) * 1000;
  bVar1 = -1 < (int)param_1;
  if (!bVar1) {
    param_1 = 0;
  }
  iVar12 = param_1 << 2;
  iVar10 = 1;
  piVar8 = (int *)PTR_socketList_0043076c;
  piVar9 = (int *)PTR_socketMax_00430768;
  for (; (int)param_1 < *piVar9; param_1 = param_1 + 1) {
    iVar11 = *(int *)(*piVar8 + iVar12);
    if (iVar11 != 0) {
      uVar14 = *(uint *)(iVar11 + 0xb0) >> 5;
      uVar13 = iVar10 << (*(uint *)(iVar11 + 0xb0) & 0x1f);
      if ((*(uint *)(iVar11 + 0xa0) & 2) != 0) {
        puVar5 = (uint *)(iVar2 + uVar14 * 4);
        *puVar5 = *puVar5 | uVar13;
        local_34 = piVar9;
        local_30 = piVar8;
        local_2c = iVar10;
        iVar15 = socketInputBuffered(param_1);
        iVar10 = local_2c;
        piVar8 = local_30;
        piVar9 = local_34;
        if (0 < iVar15) {
          local_40 = 0;
          local_3c = 0;
        }
      }
      uVar6 = *(uint *)(iVar11 + 0xa0);
      if ((uVar6 & 4) != 0) {
        puVar5 = (uint *)(iVar3 + uVar14 * 4);
        *puVar5 = *puVar5 | uVar13;
      }
      if ((uVar6 & 8) != 0) {
        puVar5 = (uint *)(iVar4 + uVar14 * 4);
        *puVar5 = *puVar5 | uVar13;
      }
    }
    iVar12 = iVar12 + 4;
    if (bVar1) break;
  }
  local_38 = (*(code *)PTR_select_00430a78)
                       (*(int *)PTR_socketHighestFd_004307a4 + 1,iVar2,iVar3,iVar4,&local_40);
  if (0 < local_38) {
    param_1 = param_1 & -(uint)bVar1;
    iVar12 = param_1 << 2;
    iVar10 = 1;
    piVar8 = (int *)PTR_socketList_0043076c;
    piVar9 = (int *)PTR_socketMax_00430768;
    while ((int)param_1 < *piVar9) {
      iVar11 = *(int *)(*piVar8 + iVar12);
      if (iVar11 != 0) {
        uVar13 = iVar10 << (*(uint *)(iVar11 + 0xb0) & 0x1f);
        iVar15 = (*(uint *)(iVar11 + 0xb0) >> 5) * 4;
        if (((uVar13 & *(uint *)(iVar2 + iVar15)) != 0) ||
           (local_34 = piVar9, local_30 = piVar8, local_2c = iVar10,
           iVar7 = socketInputBuffered(param_1), iVar10 = local_2c, piVar8 = local_30,
           piVar9 = local_34, 0 < iVar7)) {
          *(uint *)(iVar11 + 0xbc) = *(uint *)(iVar11 + 0xbc) | 2;
        }
        if ((uVar13 & *(uint *)(iVar3 + iVar15)) != 0) {
          *(uint *)(iVar11 + 0xbc) = *(uint *)(iVar11 + 0xbc) | 4;
        }
        if ((uVar13 & *(uint *)(iVar4 + iVar15)) != 0) {
          *(uint *)(iVar11 + 0xbc) = *(uint *)(iVar11 + 0xbc) | 8;
        }
      }
      param_1 = param_1 + 1;
      if (bVar1) break;
      iVar12 = iVar12 + 4;
    }
  }
  bfree(iVar2);
  bfree(iVar3);
  bfree(iVar4);
  return local_38;
}

