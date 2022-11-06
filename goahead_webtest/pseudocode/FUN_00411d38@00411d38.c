
void FUN_00411d38(void)

{
  if (-1 < DAT_00430c24) {
    socketCloseConnection();
    DAT_00430c24 = -1;
  }
  bfreeSafe(DAT_00430c14);
  bfreeSafe(DAT_00430c10);
  DAT_00430c10 = 0;
  DAT_00430c14 = 0;
  return;
}

