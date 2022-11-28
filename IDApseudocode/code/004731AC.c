int __fastcall sub_4731AC(int a1)
{
  char *v1; // $v0
  int v3; // $v0
  char v5[1024]; // [sp+20h] [-414h] BYREF
  int v6; // [sp+420h] [-14h] BYREF
  int v7; // [sp+424h] [-10h] BYREF
  int v8[3]; // [sp+428h] [-Ch] BYREF

  v8[0] = 0;
  v7 = 0;
  v6 = 0;
  v1 = httpd_get_parm(a1, "name");
  if ( v1 )
    user_get_ddate(v1, v8, &v7, &v6);
  v3 = sprintf(v5, "{\"tm\":%u,\"login_num\":%u,\"state\":%u}", v8[0], v7, v6);
  return httpd_cgi_ret(a1, v5, v3, 4);
}
// 6A8980: using guessed type int __fastcall user_get_ddate(_DWORD, _DWORD, _DWORD, _DWORD);

