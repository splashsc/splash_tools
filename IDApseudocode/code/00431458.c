int __fastcall jhl_user_login_add(_DWORD *a1, void *a2, const char *a3, char a4)
{
  unsigned int v7; // $s5
  void **v8; // $s1
  void **v9; // $s0
  int v10; // $s6
  int v11; // $v0
  int v13; // $v0
  void *v14; // $v0
  void *v15; // $s0
  int v16; // $v1
  int v17; // $a0
  int v18; // $a2
  int v19; // $a1
  void *v20; // $v1
  int v21; // $v0
  void **v22; // $v1
  int v23; // $a2
  _DWORD *v24; // $a1
  void *v25; // $v0

  v7 = get_sys_time();
  if ( v7 >= 0x4DB659DC && a3 )
  {
    if ( !user_login_init )
      jhl_user_login_init();
    v8 = (void **)user_login_list;
    if ( user_login_list != &user_login_list )
    {
      v9 = *(void ***)user_login_list;
      if ( v7 - *((_DWORD *)user_login_list + 7) < 0xE11 )
      {
        v10 = *(unsigned __int8 *)a1;
        if ( *((unsigned __int8 *)user_login_list + 8) == v10 )
          goto LABEL_11;
        while ( v9 != &user_login_list )
        {
          v8 = v9;
          if ( v7 - (unsigned int)v9[7] >= 0xE11 )
            break;
          v11 = *((unsigned __int8 *)v9 + 8);
          v9 = (void **)*v9;
          if ( v11 == v10 )
          {
LABEL_11:
            if ( v10 )
            {
              if ( !memcmp(v8 + 3, a1 + 1, 0x10u) && v8[8] == a2 )
                return 0;
            }
            else if ( v8[3] == (void *)a1[1] && v8[8] == a2 )
            {
              return 0;
            }
          }
        }
      }
    }
    v13 = user_login_num;
    if ( user_login_num >= 100 )
    {
      v22 = off_66B5E4;
      v23 = (int)*off_66B5E4;
      v24 = off_66B5E4[1];
      *(_DWORD *)(v23 + 4) = v24;
      *v24 = v23;
      *v22 = (void *)1048832;
      v22[1] = (void *)2097664;
      user_login_num = v13 - 1;
      _mem_free(v22);
      _mem_malloc(72, "jhl_user_login_add", 566);
      v15 = v25;
      if ( !v25 )
        goto LABEL_21;
      goto LABEL_20;
    }
    _mem_malloc(72, "jhl_user_login_add", 566);
    v15 = v14;
    if ( v14 )
    {
LABEL_20:
      v16 = a1[4];
      v17 = a1[3];
      v18 = a1[1];
      v19 = a1[2];
      *((_DWORD *)v15 + 2) = *a1;
      *((_DWORD *)v15 + 3) = v18;
      *((_DWORD *)v15 + 4) = v19;
      *((_DWORD *)v15 + 5) = v17;
      *((_DWORD *)v15 + 6) = v16;
      *((_DWORD *)v15 + 7) = v7;
      *((_DWORD *)v15 + 8) = a2;
      *((_BYTE *)v15 + 36) = a4;
      snprintf((char *)v15 + 40, 32, "%s", a3);
      v20 = user_login_list;
      v21 = user_login_num + 1;
      *((_DWORD *)user_login_list + 1) = v15;
      *(_DWORD *)v15 = v20;
      *((_DWORD *)v15 + 1) = &user_login_list;
      user_login_list = v15;
      user_login_num = v21;
LABEL_21:
      jhl_user_login_save();
      return 0;
    }
  }
  return 0;
}
// 43162C: variable 'v14' is possibly undefined
// 431778: variable 'v25' is possibly undefined
// 66B5E0: using guessed type void *user_login_list;
// 66B5E4: using guessed type void **off_66B5E4;
// 67D2E4: using guessed type int user_login_init;
// 67D2E8: using guessed type int user_login_num;

