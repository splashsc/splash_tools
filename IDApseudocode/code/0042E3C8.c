void __fastcall mem_list_del(int a1)
{
  _DWORD *v1; // $v0
  _DWORD *v2; // $v1
  _DWORD *v3; // $a1
  bool v4; // dc
  _DWORD *v5; // $a2
  int v6; // $a3

  v1 = (_DWORD *)((char *)&ll_mem_debug_hash + 4 * (a1 & 0xFFF));
  while ( 1 )
  {
    v1 = (_DWORD *)*v1;
    if ( !v1 )
      break;
    if ( a1 == v1[2] )
    {
      v2 = (_DWORD *)*v1;
      v3 = (_DWORD *)v1[1];
      v4 = *v1 == 0;
      *v3 = *v1;
      if ( !v4 )
        v2[1] = v3;
      v5 = (_DWORD *)*(v1 - 1);
      v6 = *(v1 - 2);
      *v1 = 1048832;
      v1[1] = 2097664;
      *(_DWORD *)(v6 + 4) = v5;
      *v5 = v6;
      *(v1 - 2) = 1048832;
      *(v1 - 1) = 2097664;
      free(v1 - 2);
      return;
    }
  }
}

