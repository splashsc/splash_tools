int __fastcall web_get_user_agent(unsigned __int8 *a1, int a2, _BYTE *a3, int a4)
{
  unsigned __int8 *v7; // $v0
  unsigned __int8 *v9; // $fp
  unsigned __int8 *v10; // $v0
  unsigned __int8 *v11; // $s7
  int v12; // $s0
  _BOOL4 v13; // $v0
  bool v14; // dc
  int result; // $v0
  int v16; // $s0
  unsigned __int8 *v17; // $v0
  unsigned __int8 *v18; // $a0
  _BYTE *v19; // $s4
  unsigned __int8 *v20; // $v0
  unsigned __int8 *v21; // $a0
  _BOOL4 i; // $v1
  _BYTE *v23; // [sp+1Ch] [-Ch]

  v7 = ShiBie_find(a1, a2, "(", 1);
  v9 = v7 + 1;
  if ( !v7 )
    return 0;
  v10 = ShiBie_find(v7 + 1, a2 - (v9 - a1), ")", 1);
  v11 = v10;
  if ( !v10 )
    return 0;
  v12 = v10 - v9;
  if ( ShiBie_find(v9, v10 - v9, "iPhone", 6) )
  {
    v13 = v9 < v11;
    goto LABEL_5;
  }
  v14 = ShiBie_find(v9, v12, "Android", 7) != 0;
  v13 = v9 < v11;
  if ( !v14 )
  {
    v14 = ShiBie_find(v9, v12, "iPad", 4) != 0;
    v13 = v9 < v11;
    if ( !v14 )
    {
      v14 = ShiBie_find(v9, v12, "iPod", 4) != 0;
      v13 = v9 < v11;
      if ( !v14 )
      {
        v14 = ShiBie_find(v9, v12, "Windows Phone", 13) != 0;
        v13 = v9 < v11;
        if ( !v14 )
        {
          v14 = ShiBie_find(v9, v12, "Symbian", 7) != 0;
          v13 = v9 < v11;
          if ( !v14 )
          {
            v14 = ShiBie_find(v9, v12, "BlackBerry", 10) != 0;
            v13 = v9 < v11;
            if ( !v14 )
            {
              if ( ShiBie_find(v9, v12, "Windows NT", 10) || ShiBie_find(v9, v12, "Macintosh", 9) )
              {
                *a3 = 80;
                a3[1] = 67;
                a3[2] = 0;
                return 0;
              }
              return 0;
            }
          }
        }
      }
    }
  }
LABEL_5:
  v14 = !v13;
  result = 0;
  if ( !v14 )
  {
    v16 = 0;
    if ( a4 > 0 )
    {
      v23 = a3;
      while ( 1 )
      {
        if ( !strnicmp(v9, "U;", 2) )
        {
          v9 += 3;
          goto LABEL_9;
        }
        if ( !strnicmp(v9, "zh-cn", 5) )
          break;
        v14 = strnicmp(v9, "en_us", 5) == 0;
        v17 = v9 + 5;
        if ( v14 )
          goto LABEL_14;
        v14 = strnicmp(v9, "en-us", 5) == 0;
        v17 = v9 + 5;
        if ( v14 )
          goto LABEL_14;
        v14 = strnicmp(v9, "zh_cn", 5) == 0;
        v17 = v9 + 5;
        if ( v14 )
          goto LABEL_14;
        v14 = strnicmp(v9, "Linux", 5) == 0;
        v17 = v9 + 5;
        if ( v14 )
          goto LABEL_14;
        if ( !strnicmp(v9, "like", 4) )
        {
          v20 = v9 + 4;
        }
        else
        {
          v14 = strnicmp(v9, "java", 4) == 0;
          v20 = v9 + 4;
          if ( !v14 )
          {
            ++v16;
            *v23++ = *v9++;
            goto LABEL_9;
          }
        }
        if ( v20 >= v11 )
          goto LABEL_19;
        v21 = v9 + 5;
        if ( v9[4] != 59 )
        {
          for ( i = v21 < v11; ; i = v21 < v11 )
          {
            ++v21;
            if ( !i )
              break;
            v9 = v21;
            if ( *(v21 - 1) == 59 )
              goto LABEL_9;
          }
          v19 = &a3[v16];
          if ( !v16 )
            return 0;
LABEL_21:
          *v19 = 0;
          return v16;
        }
        v9 += 5;
LABEL_9:
        if ( v9 >= v11 )
          goto LABEL_19;
        if ( v16 >= a4 )
          goto LABEL_20;
      }
      v17 = v9 + 5;
LABEL_14:
      if ( v17 >= v11 )
        goto LABEL_19;
      v18 = v9 + 6;
      if ( v9[5] != 59 )
      {
        while ( 1 )
        {
          v14 = v18++ < v11;
          if ( !v14 )
            break;
          v9 = v18;
          if ( *(v18 - 1) == 59 )
            goto LABEL_9;
        }
LABEL_19:
        if ( !v16 )
          return 0;
LABEL_20:
        v19 = &a3[v16];
        goto LABEL_21;
      }
      v9 += 6;
      goto LABEL_9;
    }
  }
  return result;
}
// 6A88B8: using guessed type int __fastcall strnicmp(_DWORD, _DWORD, _DWORD);

