
char * dirname(char *__path)

{
  int iVar1;
  int in_a1;
  int in_a2;
  
  iVar1 = (*(code *)PTR_strrchr_00430a58)();
  if (iVar1 != 0) {
    if ((*(char *)(iVar1 + 1) != '\0') || (iVar1 != in_a1)) {
      if (iVar1 - in_a1 < in_a2) {
        (*(code *)PTR_strncpy_00430a04)();
        __path[iVar1 - in_a1] = '\0';
        return __path;
      }
      (*(code *)PTR_strncpy_00430a04)(__path);
      __path[in_a2 + -1] = '\0';
      return __path;
    }
    (*(code *)PTR_strncpy_00430a04)(__path,".",4);
  }
  (*(code *)PTR_strcpy_00430ad8)(__path,".");
  return __path;
}

