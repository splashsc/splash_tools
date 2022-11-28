int __fastcall _lan_vlan_asp(int a1)
{
  const char **v1; // $s2
  int v3; // $s4
  int v4; // $s1
  char *v5; // $a0
  int v6; // $s1
  int v7; // $s0
  int v8; // $s0
  char *v9; // $v0
  char *v11; // $v0
  char v12[500]; // [sp+18h] [-284h] BYREF
  char v13[72]; // [sp+20Ch] [-90h] BYREF
  char v14[72]; // [sp+254h] [-48h] BYREF

  v1 = (const char **)v13;
  memset(v13, 0, sizeof(v13));
  memset(v14, 0, 0x40u);
  v3 = get_lans_num();
  v4 = httpd_get_json_parm(a1, (int)"lan_vlan");
  memset(v12, 0, sizeof(v12));
  if ( v4 )
  {
    v5 = *(char **)(v4 + 16);
  }
  else
  {
    if ( v3 > 0 )
    {
      do
      {
        v11 = &v14[strlen(v14)];
        ++v4;
        *v11 = 49;
        v11[1] = 124;
        v11[2] = 0;
      }
      while ( v3 != v4 );
      if ( split_string(v14, 124, v13, 16) < v3 )
      {
LABEL_7:
        v8 = 0;
        if ( v12[0] )
          goto LABEL_9;
        goto LABEL_8;
      }
LABEL_5:
      v6 = 0;
      v7 = 0;
      do
      {
        ++v6;
        v7 += sprintf(&v12[v7], "%s|", *v1++);
      }
      while ( v6 < v3 );
      goto LABEL_7;
    }
    v5 = v14;
  }
  if ( split_string(v5, 124, v13, 16) >= v3 )
  {
    if ( v3 <= 0 )
      goto LABEL_9;
    goto LABEL_5;
  }
  if ( !v12[0] )
  {
    v8 = 0;
    if ( v3 > 0 )
    {
      do
      {
LABEL_8:
        ++v8;
        v9 = &v12[strlen(v12)];
        *v9 = 49;
        v9[1] = 124;
        v9[2] = 0;
      }
      while ( v8 < v3 );
      goto LABEL_9;
    }
  }
LABEL_9:
  nvram_set("lan_vlan", v12);
  jhl_gl_net_restart_timer(1000);
  return 1;
}
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A87A0: using guessed type int get_lans_num(void);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

