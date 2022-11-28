int __fastcall sub_434B8C(int a1, int a2)
{
  char *v4; // $a1
  int v5; // $s4
  char **v6; // $s0
  char *v7; // $v0
  char *v8; // $s1
  unsigned int v9; // $fp
  int result; // $v0
  signed int v11; // $v0
  const char *v12; // $v0
  char v13[256]; // [sp+28h] [-120h] BYREF
  unsigned int v14; // [sp+128h] [-20h] BYREF
  unsigned int v15; // [sp+12Ch] [-1Ch] BYREF
  unsigned int v16; // [sp+130h] [-18h] BYREF
  unsigned int v17; // [sp+134h] [-14h] BYREF
  unsigned int v18; // [sp+138h] [-10h] BYREF
  unsigned int v19; // [sp+13Ch] [-Ch] BYREF
  char *v20; // [sp+140h] [-8h] BYREF

  v4 = "router_name";
  v5 = 0;
  v6 = &off_665620;
  do
  {
    v7 = httpd_get_parm(a1, v4);
    v8 = v7;
    if ( !v7 || !strcmp(v7, "undefined") )
      goto LABEL_25;
    v9 = (unsigned int)v6[1];
    if ( v9 == 3 )
    {
      v11 = strtol(v8, &v20, 10);
      if ( v8 == v20 || *v20 || v11 < (int)v6[2] )
      {
LABEL_14:
        sprintf(v13, "The field \"%s\" is invalid. Please report this problem.", *v6);
        resmsg_set(v13);
        return 0;
      }
      goto LABEL_18;
    }
    if ( v9 < 4 )
    {
      if ( v9 != 1 )
        goto LABEL_19;
      v11 = strlen(v8);
      if ( v11 < (int)v6[2] )
        goto LABEL_14;
LABEL_18:
      if ( (int)v6[3] < v11 )
        goto LABEL_14;
LABEL_19:
      if ( !a2 )
        goto LABEL_25;
LABEL_20:
      v12 = (const char *)nvram_get(*v6);
      if ( !v12 || strcmp(v12, v8) )
      {
        if ( v6[1] != (char *)6 )
          v5 = 1;
        nvram_set(*v6, v8);
      }
      goto LABEL_25;
    }
    if ( v9 == 4 )
    {
      if ( sscanf(v8, "%3u.%3u.%3u.%3u", &v14, &v15, &v16, &v17) != 4
        || v14 >= 0x100
        || v15 >= 0x100
        || v16 >= 0x100
        || v17 >= 0x100 )
      {
        goto LABEL_14;
      }
      if ( a2 )
        goto LABEL_20;
    }
    else
    {
      if ( v9 != 5 )
        goto LABEL_19;
      if ( sscanf(v8, "%2x:%2x:%2x:%2x:%2x:%2x", &v14, &v15, &v16, &v17, &v18, &v19) != 6
        || v14 >= 0x100
        || v15 >= 0x100
        || v16 >= 0x100
        || v17 >= 0x100
        || v18 >= 0x100
        || v19 >= 0x100 )
      {
        goto LABEL_14;
      }
      if ( a2 )
        goto LABEL_20;
    }
LABEL_25:
    v6 += 4;
    v4 = *v6;
  }
  while ( *v6 );
  if ( a2 )
    result = v5;
  else
    result = 1;
  return result;
}
// 665620: using guessed type char *off_665620;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

