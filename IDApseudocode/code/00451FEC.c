int __fastcall sub_451FEC(int a1)
{
  int result; // $v0

  if ( ai_sn_pub_check_token(a1) )
    result = httpd_cgi_ret(a1, "?", 1, 4);
  else
    result = ai_sn_data(a1);
  return result;
}

