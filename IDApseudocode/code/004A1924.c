int __fastcall trace_data(int a1)
{
  char *v1; // $v0
  __pid_t v3; // $s2
  size_t v4; // $v0
  int v5; // $s1
  unsigned int v6; // $s2
  unsigned int v7; // $v0
  char *v9; // $v0
  char v10[4096]; // [sp+18h] [-2080h] BYREF
  char v11[4096]; // [sp+1018h] [-1080h] BYREF
  char v12[128]; // [sp+2018h] [-80h] BYREF

  v1 = httpd_get_parm(a1, (char *)&off_64CC40);
  if ( !v1 )
  {
    strcpy(v11, "{\"code\":0,\"error\":\"\",\"data\":{");
    goto LABEL_10;
  }
  v3 = J_atoi(v1);
  strcpy(v11, "{\"code\":0,\"error\":\"\",\"data\":{");
  if ( v3 <= 0 )
  {
LABEL_10:
    strcpy(&v11[29], "\"msg\":\"\"");
    v6 = 4059;
    v5 = 37;
    goto LABEL_6;
  }
  strcpy(&v11[29], "\"msg\":\"");
  sprintf(v12, "/tmp/trace_%d", v3);
  v10[f_read(v12, v10, 5000)] = 0;
  if ( kill(v3, 0) )
  {
    v9 = &v10[strlen(v10)];
    *(_DWORD *)v9 = -491590468;
    *(_DWORD *)v9 = -491590468;
    *((_DWORD *)v9 + 1) = -120921667;
    v9[8] = 10;
    v9[9] = 0;
    unlink(v12);
  }
  get_json_data_safe2(v10, &v11[36]);
  v4 = strlen(v11);
  v5 = v4 + 1;
  v6 = 4096 - (v4 + 1);
  *(_WORD *)&v11[v4] = 34;
LABEL_6:
  v7 = snprintf(&v11[v5], v6, "}}");
  if ( v7 >= v6 )
    v7 = 4095 - v5;
  return httpd_cgi_ret(a1, v11, v7 + v5, 4);
}
// 642164: using guessed type __int16 word_642164;
// 64CC40: using guessed type void *off_64CC40;
// 6A81FC: using guessed type int __fastcall get_json_data_safe2(_DWORD, _DWORD);
// 6A869C: using guessed type int __fastcall f_read(_DWORD, _DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

