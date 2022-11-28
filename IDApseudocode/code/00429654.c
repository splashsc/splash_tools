int __fastcall sub_429654(int a1)
{
  char *v2; // $v0
  char *v3; // $s1
  int v4; // $v0
  int v5; // $a2
  char v7[1028]; // [sp+18h] [-404h] BYREF

  v3 = httpd_get_parm(a1, "user");
  v2 = httpd_get_parm(a1, "password");
  if ( v3 )
  {
    if ( v2 )
      goto LABEL_3;
  }
  else
  {
    v3 = "";
    if ( v2 )
      goto LABEL_3;
  }
  v2 = "";
LABEL_3:
  v4 = usb_httpd_cgi_user_check(v3, (int)v2);
  if ( v4 <= 0 )
  {
    if ( !v4 )
    {
      v5 = sprintf(
             v7,
             "<html><head><script type='text/javascript'>function init(){window.open('%s','_self');}</script></head><body"
             " onLoad='init();'></body></html>",
             "/usb_login.htm?flag=0");
      return httpd_cgi_ret(a1, v7, v5, 4);
    }
    v5 = 0;
  }
  else
  {
    v5 = sprintf(
           v7,
           "<html><head><script type='text/javascript'>function init(){window.open('%s','_self');}</script></head><body o"
           "nLoad='init();'></body></html>",
           "/usb_list.html");
  }
  *(_DWORD *)(a1 + 36) |= 0x1000u;
  return httpd_cgi_ret(a1, v7, v5, 4);
}

