void __fastcall iptv_token_del(void *a1)
{
  char *v1; // $v0
  _DWORD *v2; // $a1
  int v3; // $a2
  _DWORD *v4; // $v1
  int v5; // $v0

  v1 = (char *)a1 + 44;
  if ( a1 )
  {
    v2 = (_DWORD *)*((_DWORD *)a1 + 12);
    v3 = *((_DWORD *)a1 + 11);
    v4 = (_DWORD *)*((_DWORD *)a1 + 14);
    *(_DWORD *)(v3 + 4) = v2;
    *v2 = v3;
    *((_DWORD *)a1 + 11) = v1;
    *((_DWORD *)a1 + 12) = v1;
    if ( v4 )
    {
      v5 = *((_DWORD *)a1 + 13);
      *v4 = v5;
      if ( v5 )
        *(_DWORD *)(v5 + 4) = v4;
      *((_DWORD *)a1 + 13) = 0;
      *((_DWORD *)a1 + 14) = 0;
    }
    _mem_free(a1);
  }
}

