char *__fastcall mem_list_add(int a1, const char *a2, int a3, int a4)
{
  char *result; // $v0
  char *v9; // $s0
  int v10; // $v0
  int v11; // $a0
  char *v12; // $a1
  int v13; // $v1

  result = (char *)calloc(0x5Cu, 1u);
  v9 = result;
  if ( result )
  {
    *(_DWORD *)result = result;
    *((_DWORD *)result + 1) = result;
    *((_DWORD *)result + 2) = 0;
    *((_DWORD *)result + 3) = 0;
    snprintf(result + 20, 64, "%s", a2);
    v10 = 4 * (a1 & 0xFFF);
    v11 = *(_DWORD *)((char *)&ll_mem_debug_hash + v10);
    *((_DWORD *)v9 + 21) = a3;
    *((_DWORD *)v9 + 22) = a4;
    *((_DWORD *)v9 + 4) = a1;
    v12 = v9 + 8;
    *((_DWORD *)v9 + 2) = v11;
    if ( v11 )
      *(_DWORD *)(v11 + 4) = v12;
    result = (char *)&ll_mem_debug_hash + v10;
    v13 = ll_mem_debug_list;
    *(_DWORD *)result = v12;
    *((_DWORD *)v9 + 3) = result;
    ll_mem_debug_list = (int)v9;
    *(_DWORD *)(v13 + 4) = v9;
    *(_DWORD *)v9 = v13;
    *((_DWORD *)v9 + 1) = &ll_mem_debug_list;
  }
  return result;
}
// 67D060: using guessed type int ll_mem_debug_list;

