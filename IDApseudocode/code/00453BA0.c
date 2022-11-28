int del_vpnmessage_file()
{
  FILE *v0; // $v0
  FILE *v1; // $fp
  FILE *v2; // $s2
  char v4[1024]; // [sp+18h] [-400h] BYREF

  memset(v4, 0, sizeof(v4));
  v0 = fopen("/var/log/messages_tmp", "w");
  if ( !v0 )
    return -1;
  v1 = v0;
  v2 = fopen("/var/log/messages", "r");
  if ( v2 )
  {
    while ( fgets(v4, 1023, v2) )
    {
      if ( !strstr(v4, "pptpd[") && !strstr(v4, "pptp[") && !strstr(v4, "xl2tpd[") && !strstr(v4, "pppd[") )
        fputs(v4, v1);
    }
    fclose(v1);
    fclose(v2);
  }
  else
  {
    fclose(v1);
  }
  unlink("/var/log/messages");
  rename("/var/log/messages_tmp", "/var/log/messages");
  return 0;
}

