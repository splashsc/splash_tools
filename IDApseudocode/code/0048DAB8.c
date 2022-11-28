int __fastcall GetIpsecSaStatus(const char *a1, char *a2, const char *a3, void *a4, size_t n)
{
  int v9; // $s5
  FILE *v10; // $s4
  unsigned int v11; // $a2
  int v12; // $s3
  char *v13; // $v0
  bool v14; // dc
  struct hostent *v16; // $v0
  char *v17; // $a1
  int v18; // $a0
  char v19[128]; // [sp+18h] [-98h] BYREF
  char v20[4]; // [sp+98h] [-18h] BYREF
  char *v21; // [sp+9Ch] [-14h]
  char *v22; // [sp+A0h] [-10h]

  memset(v19, 0, sizeof(v19));
  if ( !a1 || !a2 || !*a2 )
    return 0;
  v9 = strcmp(a2, "dynamic");
  if ( v9 )
  {
    v12 = 0;
    if ( !is_domain(a2) )
      goto LABEL_14;
    v16 = gethostbyname(a2);
    v9 = 0;
    if ( !v16 )
      return v9;
    v17 = *v16->h_addr_list;
    if ( !v17 )
      return v9;
    v18 = v16->h_addrtype;
    if ( (v18 & 0xFFFFFFF7) != 2 )
      return v9;
    a2 = v19;
    if ( inet_ntop(v18, v17, v19, 0x80u) )
    {
      v12 = 0;
      goto LABEL_14;
    }
    return 0;
  }
  if ( a3 )
  {
    v10 = fopen("/tmp/spdump", "r");
    if ( v10 )
    {
      do
      {
        if ( !fgets(v19, 128, v10) )
        {
          fclose(v10);
          return v9;
        }
      }
      while ( split_string(v19, 124, v20, 4) < 4 || strcmp(a3, v21) );
      a2 = v22;
      fclose(v10);
      if ( !a2 )
        return v9;
      memset(a4, 0, n);
      v11 = strlen(a2);
      if ( n >= v11 )
        memcpy(a4, a2, v11);
      v12 = 0;
LABEL_14:
      while ( 1 )
      {
        v13 = strstr(a1, a2);
        if ( !v13 )
          break;
        a1 = &v13[strlen(a2)];
        if ( *a1 == 124 )
        {
          v14 = v12 == 1;
          v12 = 1;
          if ( v14 )
            return 1;
        }
      }
      return 0;
    }
  }
  return v9;
}
// 6A8224: using guessed type int __fastcall is_domain(_DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);

