int jhl_user_login_init()
{
  char *v0; // $v0
  const char *v1; // $s0
  char *v2; // $v0
  const char *v3; // $s1
  char *v5; // $v0
  char *v6; // $s0
  int v7; // $v0
  const char *v8; // $s7
  uint32_t v9; // $fp
  int v10; // $v0
  int v11; // $a0
  int v12; // $v0
  const char *v13; // $a3
  char v14; // $v0
  _DWORD *v15; // $a1
  int v16; // $v1
  char *v17; // $v0
  char v18[102400]; // [sp+18h] [-19040h] BYREF
  _DWORD v19[5]; // [sp+19018h] [-40h] BYREF
  const char *v20; // [sp+1902Ch] [-2Ch]

  v0 = (char *)nvram_get("jhluser_login");
  if ( !v0 )
    v0 = " ";
  if ( !*v0 )
    v0 = " ";
  strlcpy(v18, v0, 102400);
  v1 = v18;
  while ( *v1 )
  {
    v2 = strchr(v1, 60);
    if ( !v2 )
    {
      if ( split_string(v1, 124, v19, 6) < 5 )
        break;
      _mem_malloc(72, "jhl_user_login_init", 455);
      v6 = v17;
      if ( !v17 )
        break;
      v3 = 0;
      goto LABEL_12;
    }
    *v2 = 0;
    v3 = v2 + 1;
    if ( split_string(v1, 124, v19, 6) >= 5 && (_mem_malloc(72, "jhl_user_login_init", 455), (v6 = v5) != 0) )
    {
LABEL_12:
      v7 = J_atohx16(v19[0]);
      v8 = v20;
      v9 = v7;
      if ( v20 && (strchr(v20, 46) || strchr(v8, 58)) )
        StrToIpaddr(v8, v6 + 8);
      else
        *((_DWORD *)v6 + 3) = htonl(v9);
      v10 = J_atohx16(v19[1]);
      v11 = v19[2];
      *((_DWORD *)v6 + 7) = v10;
      v12 = J_atohx16(v11);
      v13 = (const char *)v19[3];
      *((_DWORD *)v6 + 8) = v12;
      snprintf(v6 + 40, 31, "%s", v13);
      v14 = J_atoi(v19[4]);
      v15 = user_login_list;
      v6[36] = v14;
      v16 = user_login_num;
      v15[1] = v6;
      *(_DWORD *)v6 = v15;
      *((_DWORD *)v6 + 1) = &user_login_list;
      user_login_list = v6;
      user_login_num = v16 + 1;
      v1 = v3;
      if ( !v3 )
        break;
    }
    else
    {
      v1 = v3;
      if ( !v3 )
        break;
    }
  }
  user_login_init = 1;
  return 0;
}
// 43111C: variable 'v5' is possibly undefined
// 431254: variable 'v17' is possibly undefined
// 66B5E0: using guessed type void *user_login_list;
// 67D2E4: using guessed type int user_login_init;
// 67D2E8: using guessed type int user_login_num;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8244: using guessed type int __fastcall J_atohx16(_DWORD);
// 6A8284: using guessed type int __fastcall StrToIpaddr(_DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

