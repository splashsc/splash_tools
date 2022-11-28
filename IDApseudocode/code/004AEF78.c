int __fastcall sub_4AEF78(int a1)
{
  char *v2; // $a1
  const char *v3; // $v0
  char *v4; // $v1
  int v5; // $t1
  int v6; // $t0
  int v7; // $a3
  int v8; // $a2
  char v10[1024]; // [sp+18h] [-400h] BYREF

  v2 = httpd_get_parm(a1, "num");
  if ( v2 )
    sq2_file_send_sq_num(2, v2);
  v3 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  v4 = v10;
  do
  {
    v5 = *(_DWORD *)v3;
    v6 = *((_DWORD *)v3 + 1);
    v7 = *((_DWORD *)v3 + 2);
    v8 = *((_DWORD *)v3 + 3);
    v3 += 16;
    *(_DWORD *)v4 = v5;
    *((_DWORD *)v4 + 1) = v6;
    *((_DWORD *)v4 + 2) = v7;
    *((_DWORD *)v4 + 3) = v8;
    v4 += 16;
  }
  while ( v3 != "}" );
  *(_WORD *)v4 = *(_WORD *)v3;
  return httpd_cgi_ret(a1, v10, 33, 4);
}
// 6A8494: using guessed type int __fastcall sq2_file_send_sq_num(_DWORD, _DWORD);

