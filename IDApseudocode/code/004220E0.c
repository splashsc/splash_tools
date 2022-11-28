void __fastcall check_client_is_or_not_mobile(int a1)
{
  const char *v1; // $s0

  if ( a1 )
  {
    if ( (*(_DWORD *)(a1 + 32) & 0x10000) != 0 )
    {
      v1 = *(const char **)(a1 + 205528);
      if ( v1 )
      {
        if ( !strstr(v1, "iPhone")
          && !strstr(v1, "iPad")
          && !strstr(v1, "iPod")
          && !strstr(v1, "Android")
          && !strstr(v1, "IEMobile")
          && !strstr(v1, "Symbian")
          && !strstr(v1, "BlackBerry")
          && !strstr(v1, "Blazer")
          && !strstr(v1, "BOLT")
          && !strstr(v1, "Fennec")
          && !strstr(v1, "GoBrowser")
          && !strstr(v1, "lris")
          && !strstr(v1, "Maemo")
          && !strstr(v1, (const char *)&off_4CEDB4)
          && !strstr(v1, "Minimo")
          && !strstr(v1, "NetFront")
          && !strstr(v1, "Presto")
          && !strstr(v1, "SEMC")
          && !strstr(v1, "Skyfire")
          && !strstr(v1, "TeaShark")
          && !strstr(v1, "Teleca")
          && !strstr(v1, "uZardWeb")
          && !strstr(v1, "Dorothy") )
        {
          strstr(v1, "Windows Phone");
        }
      }
    }
  }
}
// 4CEDB4: using guessed type void *off_4CEDB4;

