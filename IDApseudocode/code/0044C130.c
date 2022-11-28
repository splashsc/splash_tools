int __fastcall sub_44C130(int a1)
{
  char *v2; // $s0
  char *v3; // $s1
  char *v4; // $s5
  int v5; // $s0
  unsigned int v6; // $s1
  char *v7; // $s6
  unsigned int v8; // $s2
  const char *v9; // $v0
  unsigned int v10; // $v0
  int v11; // $s0
  unsigned int v12; // $v0
  const char *v14; // $v0
  unsigned int v15; // $v0
  char v16[10240]; // [sp+18h] [-2808h] BYREF
  int v17; // [sp+2818h] [-8h]
  int v18; // [sp+281Ch] [-4h] BYREF

  v17 = 0;
  v2 = httpd_get_parm(a1, "user");
  v3 = httpd_get_parm(a1, "password");
  v4 = httpd_get_parm(a1, "callback");
  if ( v2 )
  {
    if ( v3 )
      goto LABEL_3;
  }
  else
  {
    v2 = "";
    if ( v3 )
      goto LABEL_3;
  }
  v3 = "";
LABEL_3:
  v5 = httpd_cgi_user_check(v2, v3, &v18);
  if ( v4 )
  {
    v6 = snprintf(v16, 10240, "%s(", v4);
    if ( v6 >= 0x2800 )
      v6 = 10239;
    v7 = &v16[v6];
    v8 = 10240 - v6;
  }
  else
  {
    v8 = 10240;
    v7 = v16;
    v6 = 0;
  }
  if ( v5 <= 0 )
  {
    v14 = (const char *)get_sn();
    v15 = snprintf(v7, v8, "{\"login_flag\":\"0\",\"sn\":\"%s\"}", v14);
    if ( v15 >= v8 )
      v15 = 10239 - v6;
    v11 = v15 + v6;
  }
  else
  {
    v9 = (const char *)get_sn();
    v10 = snprintf(v7, v8, "{\"login_flag\":\"1\",\"sn\":\"%s\"}", v9);
    if ( v10 >= v8 )
      v10 = 10239 - v6;
    v11 = v10 + v6;
    *(_DWORD *)(a1 + 36) |= 0x1000u;
  }
  if ( v4 )
  {
    v12 = snprintf(&v16[v11], 10240 - v11, ")");
    if ( v12 >= 10240 - v11 )
      v12 = 10239 - v11;
    v11 += v12;
  }
  return httpd_cgi_ret(a1, v16, v11, 4);
}
// 6A81D8: using guessed type int get_sn(void);

