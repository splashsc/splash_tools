int __fastcall menus_js_replace_text(int a1, const char *a2, int a3, int a4)
{
  int v8; // $fp
  int v9; // $s4
  int v10; // $s5
  _BYTE *v11; // $v0
  bool v13; // dc
  const char *v14; // $a3
  int v15; // $v0
  const char *v16; // $s7
  const char *v17; // $s7
  int v18; // $v0
  const char *v19; // $s7
  int v20; // $v0
  const char *v21; // $v0
  int v22; // $v0
  const char *v23; // $s7
  int v24; // $v0
  int v25; // $v0
  char *v26; // $a0
  const char *v27; // $a3
  int v28; // $v0
  int v29; // $v0

  v8 = 0;
LABEL_2:
  while ( 1 )
  {
    v9 = *a2;
    if ( !*a2 )
      break;
    while ( 1 )
    {
      v10 = a4 - v8;
      if ( a4 - v8 < 257 )
        goto LABEL_7;
      if ( v9 != 91 )
      {
        v11 = (_BYTE *)(a3 + v8);
        goto LABEL_6;
      }
      if ( !memcmp(a2, "[TEXT:", 6u) )
        break;
      v13 = memcmp(a2, "[HIDDEN:", 8u) != 0;
      v11 = (_BYTE *)(a3 + v8);
      if ( !v13 )
      {
        if ( !memcmp(a2 + 8, "WTOKEN:", 7u) )
        {
          v16 = a2 + 15;
          v25 = atoi(v16);
          v26 = (char *)(a3 + v8);
          if ( v25 == *(unsigned __int8 *)(a1 + 210100) )
            goto LABEL_32;
        }
        else
        {
          if ( memcmp(a2 + 8, "AUTHXX:", 7u) )
          {
            if ( !memcmp(a2 + 8, "BRIDGE:", 7u) )
              v14 = "false";
            else
              v14 = "true";
            v15 = snprintf((char *)(a3 + v8), a4 - v8, "%s", v14);
            if ( v15 >= v10 )
              v15 = v10 - 1;
            v8 += v15;
            v16 = a2 + 8;
LABEL_17:
            v17 = v16 + 1;
            do
              v18 = *(v17++ - 1);
            while ( v18 != 93 );
            a2 = v17 - 1;
            goto LABEL_2;
          }
          v16 = a2 + 15;
          v29 = atoi(v16);
          v26 = (char *)(a3 + v8);
          if ( *(_DWORD *)(a1 + 205588) < v29 )
          {
LABEL_32:
            v27 = "true";
            goto LABEL_28;
          }
        }
        v27 = "false";
LABEL_28:
        v28 = snprintf(v26, a4 - v8, "%s", v27);
        if ( v28 >= v10 )
          v28 = v10 - 1;
        v8 += v28;
        goto LABEL_17;
      }
LABEL_6:
      *v11 = v9;
      v9 = *++a2;
      ++v8;
      if ( !*a2 )
        goto LABEL_7;
    }
    v19 = a2 + 6;
    v20 = atoi(v19);
    v21 = (const char *)GET_MENU_JS_TEXT(v20, *(unsigned __int8 *)(a1 + 210102));
    v22 = snprintf((char *)(a3 + v8), a4 - v8, "%s", v21);
    if ( v22 >= v10 )
      v22 = v10 - 1;
    v8 += v22;
    v23 = v19 + 1;
    do
      v24 = *(v23++ - 1);
    while ( v24 != 93 );
    a2 = v23 - 1;
  }
LABEL_7:
  *(_BYTE *)(a3 + v8) = 0;
  return v8;
}
// 6A821C: using guessed type int __fastcall GET_MENU_JS_TEXT(_DWORD, _DWORD);

