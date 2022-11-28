int __fastcall sub_4B5F5C(int a1)
{
  int result; // $v0

  if ( httpd_get_parm(a1, "opt") )
    result = usb_email_asp(a1);
  else
    result = sub_4B3BB8(a1);
  return result;
}

