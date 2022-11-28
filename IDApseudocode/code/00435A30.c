int __fastcall httdp_proxy_check_user(int a1)
{
  char *v1; // $s0
  char *v3; // $v0
  int *v4; // $v0
  int v5; // $s2
  unsigned int v6; // $a1
  int *v8; // $v0
  char *v9; // $v0
  const char *v10; // $s0
  int v11; // $v0
  int v12; // $v0
  int v13; // $v0
  int v14; // $v0
  int v15; // $v0
  int v16; // $v0
  int v17; // $v0
  int v18; // $v0
  int v19; // $v0
  int v20; // $v0
  int v21; // $v0

  v1 = (char *)(*(_DWORD *)(a1 + 44) + 1);
  v3 = strchr(v1, 47);
  if ( v3 )
    v1 = v3 + 1;
  v5 = get_name_hash((unsigned __int8 *)v1);
  v4 = httpd_get_file(v1, v5);
  if ( v4 )
  {
    v6 = v4[3];
    return httpd_check_user(a1, v6);
  }
  v8 = httpd_find_ext_file(v1, v5);
  if ( v8 )
  {
    v6 = v8[4];
    return httpd_check_user(a1, v6);
  }
  v9 = strrchr(v1, 46);
  v10 = v9;
  if ( v9 )
  {
    v11 = strcmp(v9, ".asp");
    v6 = 4;
    if ( !v11 )
      return httpd_check_user(a1, v6);
    v12 = strcmp(v10, ".cgi");
    v6 = 4;
    if ( !v12 )
      return httpd_check_user(a1, v6);
    if ( !strcmp(v10, ".cfg") )
    {
      v6 = 4;
      return httpd_check_user(a1, v6);
    }
    v13 = strcmp(v10, ".csv");
    v6 = 4;
    if ( !v13 )
      return httpd_check_user(a1, v6);
  }
  else
  {
    v10 = "";
  }
  v14 = strcmp(v10, ".key");
  v6 = 4;
  if ( v14 )
  {
    v15 = strcmp(v10, ".crt");
    v6 = 4;
    if ( v15 )
    {
      v16 = strcmp(v10, ".pem");
      v6 = 4;
      if ( v16 )
      {
        v17 = strcmp(v10, ".txt");
        v6 = 4;
        if ( v17 )
        {
          v18 = strcmp(v10, ".data");
          v6 = 3;
          if ( v18 )
          {
            v19 = strcmp(v10, ".cap");
            v6 = 3;
            if ( v19 )
            {
              v20 = strcmp(v10, ".js");
              v6 = 0;
              if ( v20 )
              {
                v21 = strcmp(v10, ".htm");
                v6 = 0;
                if ( v21 )
                {
                  if ( !strcmp(v10, ".html") )
                    v6 = 0;
                  else
                    v6 = strcmp(v10, ".trx") != 0;
                }
              }
            }
          }
        }
      }
    }
  }
  return httpd_check_user(a1, v6);
}

