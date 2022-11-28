int __fastcall ai_sn_pub_check_token(int a1)
{
  char *v1; // $v0
  int v3; // $a0
  char *v4; // $s0
  int v5; // $v0
  char *v6; // $s2
  unsigned int v7; // $v0
  int v8; // $s0
  int result; // $v0
  char v10[128]; // [sp+18h] [-C0h] BYREF
  char v11[64]; // [sp+98h] [-40h] BYREF

  v1 = httpd_get_parm(a1, "tm");
  v3 = a1;
  v4 = v1;
  v6 = httpd_get_parm(v3, "token");
  v5 = J_atoi(v4);
  if ( dword_67D4F0 >= v5 )
    return -1;
  v8 = v5;
  v7 = snprintf(v10, 128, "%luGFX2654724QRRMLO!@$#&^HH", v5);
  if ( v7 >= 0x80 )
    v7 = 127;
  get_md5_str(v10, v7, v11);
  if ( !v6 )
    return -1;
  result = strcmp(v6, v11);
  if ( result )
    return -1;
  dword_67D4F0 = v8;
  return result;
}
// 67D4F0: using guessed type int dword_67D4F0;
// 6A8520: using guessed type int __fastcall get_md5_str(_DWORD, _DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

