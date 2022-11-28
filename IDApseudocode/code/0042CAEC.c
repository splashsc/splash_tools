int __fastcall sub_42CAEC(int a1, int a2)
{
  *(&array_conn.events + 4 * a2) = 1;
  return 0;
}

