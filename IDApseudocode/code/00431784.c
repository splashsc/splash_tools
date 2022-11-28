int __fastcall sub_431784(_DWORD *a1, int a2, const char *a3, char a4)
{
  unsigned int v8; // $s5
  int v9; // $v0
  void *v10; // $v0
  void *v11; // $s1
  int v12; // $v1
  int v13; // $a0
  int v14; // $a2
  int v15; // $a1
  void *v16; // $v1
  int v17; // $v0
  void **v19; // $v1
  int v20; // $a2
  _DWORD *v21; // $a1
  void *v22; // $v0

  v8 = get_sys_time();
  if ( v8 < 0x4DB659DC || !a3 )
    return 0;
  if ( user_login_init )
  {
    v9 = user_login_num;
    if ( user_login_num < 100 )
      goto LABEL_5;
LABEL_9:
    v19 = off_66B5E4;
    v20 = (int)*off_66B5E4;
    v21 = off_66B5E4[1];
    *(_DWORD *)(v20 + 4) = v21;
    *v21 = v20;
    *v19 = (void *)1048832;
    v19[1] = (void *)2097664;
    user_login_num = v9 - 1;
    _mem_free(v19);
    _mem_malloc(72, "jhl_user_json_add", 660);
    v11 = v22;
    if ( !v22 )
      goto LABEL_7;
    goto LABEL_6;
  }
  jhl_user_login_init();
  v9 = user_login_num;
  if ( user_login_num >= 100 )
    goto LABEL_9;
LABEL_5:
  _mem_malloc(72, "jhl_user_json_add", 660);
  v11 = v10;
  if ( v10 )
  {
LABEL_6:
    v12 = a1[4];
    v13 = a1[3];
    v14 = a1[1];
    v15 = a1[2];
    *((_DWORD *)v11 + 2) = *a1;
    *((_DWORD *)v11 + 3) = v14;
    *((_DWORD *)v11 + 4) = v15;
    *((_DWORD *)v11 + 5) = v13;
    *((_DWORD *)v11 + 6) = v12;
    *((_DWORD *)v11 + 6) = v12;
    *((_DWORD *)v11 + 7) = v8;
    *((_DWORD *)v11 + 8) = a2;
    *((_BYTE *)v11 + 36) = a4;
    snprintf((char *)v11 + 40, 32, "%s", a3);
    v16 = user_login_list;
    v17 = user_login_num + 1;
    *((_DWORD *)user_login_list + 1) = v11;
    *(_DWORD *)v11 = v16;
    *((_DWORD *)v11 + 1) = &user_login_list;
    user_login_list = v11;
    user_login_num = v17;
LABEL_7:
    jhl_user_login_save();
  }
  return 0;
}
// 43184C: variable 'v10' is possibly undefined
// 4319A4: variable 'v22' is possibly undefined
// 66B5E0: using guessed type void *user_login_list;
// 66B5E4: using guessed type void **off_66B5E4;
// 67D2E4: using guessed type int user_login_init;
// 67D2E8: using guessed type int user_login_num;

