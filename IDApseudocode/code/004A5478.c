int __fastcall format_upnp_state_data(int a1, int a2)
{
  FILE *v4; // $s3
  int i; // $s1
  int v6; // $s7
  char *v7; // $v0
  char *v8; // $v0
  int v9; // $v0
  char v11[1028]; // [sp+18h] [-404h] BYREF

  v4 = fopen("/var/spool/upnp.js", "r");
  if ( v4 )
  {
    for ( i = 0; ; i += v9 )
    {
      v6 = a2 - i;
      if ( !fgets(v11, 1024, v4) )
        break;
      printf("%s", v11);
      v7 = strchr(v11, 13);
      if ( v7 )
        *v7 = 0;
      v8 = strchr(v11, 10);
      if ( v8 )
        *v8 = 0;
      v9 = snprintf((char *)(a1 + i), a2 - i, "%s", v11);
      if ( v9 >= v6 )
        v9 = v6 - 1;
    }
    fclose(v4);
  }
  else
  {
    i = 0;
  }
  unlink("/var/spool/upnp.js");
  return i;
}

