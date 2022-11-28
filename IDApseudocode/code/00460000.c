void sub_460000()
{
  int v0; // $s0
  int v1; // $a0
  unsigned int *v2; // $v1
  const char *v3; // $v0
  unsigned int v4; // $t0
  unsigned int v5; // $a3
  unsigned int v6; // $a2
  unsigned int v7; // $a1

  jhl_parm_set("macfilterAll", " ");
  jhl_parm_commit(v1);
  v2 = &STACK[0x128];
  v3 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  do
  {
    v4 = *(_DWORD *)v3;
    v5 = *((_DWORD *)v3 + 1);
    v6 = *((_DWORD *)v3 + 2);
    v7 = *((_DWORD *)v3 + 3);
    v3 += 16;
    *v2 = v4;
    v2[1] = v5;
    v2[2] = v6;
    v2[3] = v7;
    v2 += 4;
  }
  while ( v3 != "}" );
  *(_WORD *)v2 = *(_WORD *)v3;
  httpd_cgi_ret(v0, (char *)&STACK[0x128], 33, 4);
  __asm { jr      $ra }
}
// 460030: variable 'v1' is possibly undefined
// 460094: variable 'v0' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);

