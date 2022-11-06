
int FUN_004066d0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar1 = (*(code *)PTR_open_00430958)(param_4,0x102,0x1b6);
  if (iVar1 < 0) {
    iVar3 = -1;
    iVar2 = -1;
  }
  else {
    iVar2 = (*(code *)PTR_open_00430958)(param_5,0x102,0x1b6);
    if (iVar2 < 0) {
      iVar3 = -1;
    }
    else {
      iVar3 = (*(code *)PTR_dup_004309ac)(0);
      if (iVar3 != -1) {
        iVar4 = (*(code *)PTR_dup_004309ac)(1);
        if (iVar4 != -1) {
          iVar5 = (*(code *)PTR_dup2_00430a88)(iVar1,0);
          if (iVar5 == -1) {
            iVar5 = -1;
          }
          else {
            iVar6 = (*(code *)PTR_dup2_00430a88)(iVar2,1);
            iVar5 = -1;
            if (iVar6 != -1) {
              iVar5 = (*(code *)PTR_fork_004309e8)();
              if (iVar5 == 0) {
                iVar1 = (*(code *)PTR_execve_00430a9c)(param_1,param_2,param_3);
                if (iVar1 == -1) {
                  (*(code *)PTR_puts_00430a8c)
                            ("content-type: text/html\n\nExecution of cgi process failed");
                }
                iVar1 = (*(code *)PTR_exit_00430974)(0);
                return iVar1;
              }
            }
          }
          if (-1 < iVar4) {
            (*(code *)PTR_dup2_00430a88)(iVar4,1);
            (*(code *)PTR_close_0043093c)(iVar4);
          }
          goto LAB_00406860;
        }
      }
    }
  }
  iVar5 = -1;
LAB_00406860:
  if (-1 < iVar3) {
    (*(code *)PTR_dup2_00430a88)(iVar3,0);
    (*(code *)PTR_close_0043093c)(iVar3);
  }
  if (-1 < iVar2) {
    (*(code *)PTR_close_0043093c)(iVar2);
  }
  if (-1 < iVar1) {
    (*(code *)PTR_close_0043093c)(iVar1);
  }
  return iVar5;
}

