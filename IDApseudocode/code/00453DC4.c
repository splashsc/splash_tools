char *__fastcall read_vpnmessage_file(char *a1, int a2)
{
  FILE *v4; // $s2
  char *v5; // $s4
  bool v6; // dc
  _BOOL4 v7; // $v0
  int v8; // $a1
  char *v9; // $v1
  int v10; // $v0
  _BYTE *v11; // $a0
  int v12; // $v0
  unsigned __int8 v13; // $v0
  int v14; // $v0
  int v15; // $v0
  int v16; // $v0
  char v18[1024]; // [sp+20h] [-408h] BYREF
  char *v19; // [sp+420h] [-8h]

  memset(v18, 0, sizeof(v18));
  v4 = fopen("/var/log/messages", "r");
  if ( v4 )
  {
    v5 = a1;
    v19 = "a";
LABEL_3:
    while ( 2 )
    {
      v6 = fgets(v18, 1023, v4) == 0;
      v7 = a2 < 3000;
      if ( v6 )
        goto LABEL_32;
LABEL_4:
      if ( v7 )
        goto LABEL_32;
      if ( !strstr(v18, "pptpd[") && !strstr(v18, "pptp[") && !strstr(v18, "xl2tpd[") && !strstr(v18, v19 + 22336)
        || !v18[0] )
      {
        continue;
      }
      break;
    }
    v8 = 0;
    v9 = v18;
    if ( v18[0] != 32 )
    {
LABEL_8:
      v10 = v9[1];
      goto LABEL_9;
    }
    while ( 1 )
    {
      if ( v8 )
      {
        if ( ++v8 == 3 )
        {
          *v9 = 0;
          v10 = v9[1];
        }
        else
        {
          v10 = v9[1];
          if ( v8 == 5 )
          {
            *v9 = 0;
            v11 = v9 + 1;
            if ( !v10 )
              goto LABEL_3;
            while ( 2 )
            {
              v13 = v10 - 34;
              while ( v13 < 0x1Bu && ((0x4000021u >> v13) & 1) != 0 )
              {
                *v11++ = 32;
                v14 = (char)*v11;
                v6 = v14 != 0;
                v13 = v14 - 34;
                if ( !v6 )
                  goto LABEL_27;
              }
              v12 = (char)*v11;
              if ( v12 != 10 && v12 != 13 )
              {
                LOBYTE(v10) = *++v11;
                if ( *v11 )
                  continue;
LABEL_27:
                v15 = v9[1];
                goto LABEL_28;
              }
              break;
            }
            *v11 = 0;
            v15 = v9[1];
LABEL_28:
            if ( !v15 )
              goto LABEL_3;
            v16 = snprintf(v5, a2, "\"%s <%s\",", v9 + 1, v18);
            if ( v16 >= a2 )
              v16 = a2 - 1;
            a2 -= v16;
            v5 += v16;
            v6 = fgets(v18, 1023, v4) != 0;
            v7 = a2 < 3000;
            if ( !v6 )
            {
LABEL_32:
              fclose(v4);
              return (char *)(v5 - a1);
            }
            goto LABEL_4;
          }
        }
      }
      else
      {
        v10 = v9[1];
        if ( v10 == 32 )
        {
          v10 = v9[2];
          v8 = 1;
          ++v9;
        }
        else
        {
          v8 = 1;
        }
      }
LABEL_9:
      ++v9;
      if ( !v10 )
        goto LABEL_3;
      if ( v10 != 32 )
        goto LABEL_8;
    }
  }
  return 0;
}

