int __fastcall sub_459DEC(int a1)
{
  const char *v1; // $v0
  char *v3; // $v1
  int v4; // $t0
  int v5; // $a3
  int v6; // $a2
  int v7; // $a1
  char v9[516]; // [sp+18h] [-204h] BYREF

  v1 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  v3 = v9;
  do
  {
    v4 = *(_DWORD *)v1;
    v5 = *((_DWORD *)v1 + 1);
    v6 = *((_DWORD *)v1 + 2);
    v7 = *((_DWORD *)v1 + 3);
    v1 += 16;
    *(_DWORD *)v3 = v4;
    *((_DWORD *)v3 + 1) = v5;
    *((_DWORD *)v3 + 2) = v6;
    *((_DWORD *)v3 + 3) = v7;
    v3 += 16;
  }
  while ( v1 != "}" );
  *(_WORD *)v3 = *(_WORD *)v1;
  jhl_gl_poweroff_timer(3000);
  return httpd_cgi_ret(a1, v9, 33, 4);
}

