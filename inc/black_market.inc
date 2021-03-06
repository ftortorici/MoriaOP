{Add magical plusses}
//[psect(misc$code)]
procedure add_tohit(a, b, c, i: Integer; var r: Integer);
	begin
	r:= randint(a) + randint(b) + randint(c);
	store[7].store_inven[i].sitem.tohit:= r;
	end;

{Add magical plusses}
//[psect(misc$code)]
procedure add_todam(a, b, c, i: Integer; var r: Integer);
	begin
	r:= randint(a) + randint(b) + randint(c);
	store[7].store_inven[i].sitem.todam:= r;
	end;

{Add magical plusses}
//[psect(misc$code)]
procedure add_ac(a, b, c, i: Integer; var r: Integer);
	begin
	r:= randint(a) + randint(b) + randint(c);
	store[7].store_inven[i].sitem.ac:= r;
	end;

{Add magical plusses}
//[psect(misc$code)]
procedure add_toac(a, b, c, i: Integer; var r: Integer);
	begin
	r:= randint(a) + randint(b) + randint(c);
	store[7].store_inven[i].sitem.toac:= r;
	end;

{Add magical plusses}
//[psect(misc$code)]
procedure add_p1(a, b, c, i: Integer; var r: Integer);
	begin
	r:= a + randint(b) + randint(c);
	store[7].store_inven[i].sitem.p1:= r;
	end;

//[psect(misc$code)]
procedure add_p1_rods(a, b, c, i: Integer; var r: Integer);
	begin
	r:= a + randint(b) + c;
	store[7].store_inven[i].sitem.p1:= r;
	end;

{ Soup-up the Black Market inventory - mwk}
//[psect(store$code)]
procedure soup_up_black_market(indx: Integer);
	var
	r1, r2, r3, r4, r5: Integer;

	begin
	with store[7].store_inven[indx] do
		begin
		case sitem.tval of
			10, 11, 12: { Sling ammo, bolts and arrows }
				begin
				case randint(10) of
					1, 2, 3:
						begin
						sitem.name:= sitem.name + ' of Slaying';
						add_tohit(5, 5, 1, indx, r1);
						add_todam(5, 5, 1, indx, r2);
						sitem.cost:= sitem.cost + 1250 * r1 + 1250 * r2
						end;
					4, 5:
						begin
						sitem.flags:= (sitem.flags or $00040000);
						sitem.name := sitem.name + ' of Fire';
						add_tohit(4, 4, 1, indx, r1);
						add_todam(4, 4, 1, indx, r2);
						sitem.cost:= sitem.cost + 1000 * r1 + 1000 * r2
						end;
					6, 7:
						begin
						sitem.flags:= (sitem.flags or $00008000);
						sitem.name := sitem.name + ' of Slay Evil';
						add_tohit(4, 4, 1, indx, r1);
						add_todam(4, 4, 1, indx, r2);
						sitem.cost:= sitem.cost + 1000 * r1 + 1000 * r2
						end;
					8, 9:
						begin
						sitem.flags:= (sitem.flags or $00004000);
						sitem.name := sitem.name + ' of Slay Monster';
						add_tohit(3, 2, 1, indx, r1);
						add_todam(3, 2, 1, indx, r2);
						sitem.cost:= sitem.cost + 900 * r1 + 900 * r1
						end;
					10:
						begin
						sitem.flags:= (sitem.flags or $00002000);
						sitem.name := sitem.name + ' of Dragon Slaying';
						add_tohit(8, 8, 1, indx, r1);
						add_todam(8, 8, 1, indx, r2);
						sitem.cost:= sitem.cost + 1000 * r1 + 1000 * r2
						end;
					else
						;
					end; { case }
				sitem.number:= 0;
				for r1:= 1 to 7 do
					sitem.number:= sitem.number + randint(12);

				missle_ctr      := missle_ctr + 1;
				if (missle_ctr > 65534) then
					missle_ctr:= 1;

				sitem.subval  := missle_ctr + 512;
				end;

			20: { Sling, crossbows and bows }
				begin
				add_tohit(5, 5, 1, indx, r1);
				sitem.cost:= sitem.cost + 1000 * r1 + 10000
				end;

			21, 22, 23: { Weapons }
				case randint(16) of
					1, 9:
						begin
						sitem.flags:= (sitem.flags or $01418001);
						sitem.name := sitem.name + ' (HA)';
						add_tohit(6, 6, 1, indx, r1);
						add_todam(6, 6, 1, indx, r2);
						add_toac(5, 1, 1, indx, r4);
						add_p1(1, 4, 1, indx, r5); { for sustain stat }
						sitem.cost:= sitem.cost + 1000 * r1 + 1000 * r2;
						sitem.cost:= sitem.cost + 2000 * r4;
						sitem.cost:= sitem.cost + 20000
						end;
					2, 10:
						begin
						sitem.flags:= (sitem.flags or $07B80900);
						sitem.name := sitem.name + ' [%P4] (DF)';
						add_tohit(6, 6, 1, indx, r1);
						add_todam(6, 6, 1, indx, r2);
						add_toac(5, 5, 8, indx, r4);
						sitem.cost:= sitem.cost + 1000 * r1 + 1000 * r2;
						sitem.cost:= sitem.cost + 2000 * r4;
						sitem.cost:= sitem.cost + 25000
						end;
					3, 11:
						begin
						sitem.flags:= (sitem.flags or $01004000);
						sitem.name := sitem.name + ' (SM)';
						add_tohit(4, 4, 1, indx, r1);
						add_todam(4, 4, 1, indx, r2);
						sitem.cost:= sitem.cost + 1000 * r1 + 1000 * r2;
						sitem.cost:= sitem.cost + 15000
						end;
					4, 12:
						begin
						sitem.flags:= (sitem.flags or $00002000);
						sitem.name := sitem.name + ' (SD)';
						add_tohit(5, 5, 1, indx, r1);
						add_todam(5, 5, 1, indx, r2);
						add_toac(10, 1, 1, indx, r4);
						sitem.cost:= sitem.cost + 1000 * r1 + 1000 * r2;
						sitem.cost:= sitem.cost + 5000 * r4;
						sitem.cost:= sitem.cost + 15000
						end;
					5, 13:
						begin
						sitem.flags:= (sitem.flags or $01008000);
						sitem.name := sitem.name + ' (SE)';
						add_tohit(4, 4, 1, indx, r1);
						add_todam(4, 4, 1, indx, r2);
						sitem.cost:= sitem.cost + 1000 * r1 + 1000 * r2;
						sitem.cost:= sitem.cost + 15000
						end;
					6, 14:
						begin
						sitem.flags:= (sitem.flags or $01010000);
						sitem.name := sitem.name + ' (SU)';
						add_tohit(4, 4, 1, indx, r1);
						add_todam(4, 4, 1, indx, r2);
						sitem.cost:= sitem.cost + 1000 * r1 + 1000 * r2;
						sitem.cost:= sitem.cost + 15000
						end;
					7, 15:
						begin
						sitem.flags:= (sitem.flags or $00040000);
						sitem.name := sitem.name + ' (FT)';
						add_tohit(4, 4, 1, indx, r1);
						add_todam(4, 4, 1, indx, r2);
						sitem.cost:= sitem.cost + 1000 * r1 + 1000 * r2;
						sitem.cost:= sitem.cost + 15000
						end;
					8, 16:
						begin
						sitem.flags:= (sitem.flags or $00002000);
						sitem.name := sitem.name + ' (SD)';
						add_tohit(5, 5, 1, indx, r1);
						add_todam(5, 5, 1, indx, r2);
						add_toac(10, 1, 1, indx, r4);
						sitem.cost:= sitem.cost + 1000 * r1 + 1000 * r2;
						sitem.cost:= sitem.cost + 5000 * r4;
						sitem.cost:= sitem.cost + 15000
						end;
					else
						;
					end;

			25: { Digging tools }
				begin
				add_p1(0, 3, 3, indx, r5);
				add_tohit(4, 4, 1, indx, r1);
				add_todam(4, 4, 1, indx, r2);
				sitem.cost:= sitem.cost + 1000 * r1 + 1000 * r2 + 1000 * r5;
				sitem.cost:= sitem.cost + 15000
				end;

			31: { Gloves and Gauntlets }
				case randint(2) of
					1:
						begin
						sitem.flags:= (sitem.flags or $00800000);
						sitem.name := sitem.name + ' of Free Action';
						add_ac(4, 4, 1, indx, r3);
						add_toac(4, 4, 1, indx, r4);
						sitem.cost:= sitem.cost + 1000 * r3 + 1000 * r4;
						sitem.cost:= sitem.cost + 15000
						end;
					2:
						begin
						sitem.name:= sitem.name + ' of Slaying';
						add_tohit(6, 6, 1, indx, r1);
						add_todam(6, 6, 1, indx, r2);
						add_ac(4, 4, 1, indx, r3);
						add_toac(4, 4, 1, indx, r4);
						sitem.cost:= sitem.cost + 5000 * r1 + 6000 * r2;
						sitem.cost:= sitem.cost + 1000 * r3 + 1000 * r4;
						sitem.cost:= sitem.cost + 15000
						end;
					else
						;
					end;

			32: { Cloaks }
				case randint(2) of
					1:
						begin
						sitem.name:= sitem.name + ' of Protection';
						add_ac(4, 4, 1, indx, r3);
						add_toac(4, 4, 1, indx, r4);
						sitem.cost:= sitem.cost + 5000 * r3 + 5000 * r4
						end;
					2:
						begin
						sitem.flags:= (sitem.flags or $00000100);
						sitem.name := sitem.name + ' of Stealth (%P1)';
						add_p1(0, 2, 2, indx, r5);
						add_ac(4, 4, 1, indx, r3);
						add_toac(4, 4, 1, indx, r4);
						sitem.cost:= sitem.cost + 10000 * r5 + 5000 * r3
								+ 5000 * r4
						end;
					else
						;
					end;

			33: { Helms }
				case sitem.subval of
					1, 2, 3, 4, 5:
						case randint(3) of
							1:
								begin
								sitem.flags:= (sitem.flags or $00000008);
								sitem.name := sitem.name + ' of Intelligence';
								add_p1(0, 2, 2, indx, r5);
								add_ac(4, 4, 1, indx, r3);
								add_toac(4, 4, 1, indx, r4);
								sitem.cost:= sitem.cost + 10000 * r5;
								sitem.cost:= sitem.cost + 5000 * r3 + 5000 * r4
								end;
							2:
								begin
								sitem.flags:= (sitem.flags or $00000010);
								sitem.name := sitem.name + ' of Wisdom';
								add_p1(0, 2, 2, indx, r5);
								add_ac(4, 4, 1, indx, r3);
								add_toac(4, 4, 1, indx, r4);
								sitem.cost:= sitem.cost + 10000 * r5;
								sitem.cost:= sitem.cost + 5000 * r3 + 5000 * r4
								end;
							3:
								begin
								sitem.flags:= (sitem.flags or $40000000);
								sitem.name := sitem.name + ' of Infra-Vision';
								add_p1(0, 4, 4, indx, r5);
								add_ac(4, 4, 1, indx, r3);
								add_toac(4, 4, 1, indx, r4);
								sitem.cost:= sitem.cost + 10000 * r5;
								sitem.cost:= sitem.cost + 5000 * r3 + 5000 * r4
								end;
							else
								;
						end;
					6, 7, 8:
						case randint(6) of
							1:
								begin
								sitem.flags:= (sitem.flags or $00800007);
								sitem.name := sitem.name + ' of Might';
								add_p1(0, 4, 4, indx, r5);
								add_ac(4, 4, 1, indx, r3);
								add_toac(4, 4, 1, indx, r4);
								sitem.cost:= sitem.cost + 10000 * r5;
								sitem.cost:= sitem.cost + 5000 * r3 + 5000 * r4
								end;
							2:
								begin
								sitem.flags:= (sitem.flags or $00000030);
								sitem.name := sitem.name + ' of Lordliness';
								add_p1(0, 4, 4, indx, r5);
								add_ac(4, 4, 1, indx, r3);
								add_toac(4, 4, 1, indx, r4);
								sitem.cost:= sitem.cost + 10000 * r5;
								sitem.cost:= sitem.cost + 5000 * r3 + 5000 * r4
								end;
							3:
								begin
								sitem.flags:= (sitem.flags or $01380008);
								sitem.name := sitem.name + ' of the Magi';
								add_p1(0, 4, 4, indx, r5);
								add_ac(4, 4, 1, indx, r3);
								add_toac(4, 4, 1, indx, r4);
								sitem.cost:= sitem.cost + 10000 * r5;
								sitem.cost:= sitem.cost + 5000 * r3 + 5000 * r4
								end;
							4:
								begin
								sitem.flags:= (sitem.flags or $00000020);
								sitem.name := sitem.name + ' of Beauty';
								add_p1(0, 4, 4, indx, r5);
								add_ac(4, 4, 1, indx, r3);
								add_toac(4, 4, 1, indx, r4);
								sitem.cost:= sitem.cost + 10000 * r5;
								sitem.cost:= sitem.cost + 5000 * r3 + 5000 * r4
								end;
							5:
								begin
								sitem.flags:= (sitem.flags or $01000040);
								sitem.name := sitem.name + ' of Seeing';
								add_p1(0, 4, 4, indx, r5);
								add_ac(4, 4, 1, indx, r3);
								add_toac(4, 4, 1, indx, r4);
								sitem.cost:= sitem.cost + 10000 * r5;
								sitem.cost:= sitem.cost + 5000 * r3 + 5000 * r4
								end;
							6:
								begin
								sitem.flags:= (sitem.flags or $00000800);
								sitem.name := sitem.name + ' of Regeneration';
								add_ac(4, 4, 1, indx, r3);
								add_toac(4, 4, 1, indx, r4);
								sitem.cost:= sitem.cost + 5000 * r3 + 5000 * r4
								end;
							else
								;
							end;
					else
						;
					end;

			34, 35: { Shields and Hard Armor }
				case randint(10) of
					1, 6:
						begin
						sitem.flags:= (sitem.flags or $02380000);
						sitem.name := sitem.name + ' (R)';
						add_toac(8, 8, 1, indx, r4);
						sitem.cost:= sitem.cost + 10000 * r4;
						sitem.cost:= sitem.cost + 50000
						end;
					2, 7:
						begin
						sitem.flags:= (sitem.flags or $00100000);
						sitem.name := sitem.name + ' (RA)';
						add_toac(8, 8, 1, indx, r4);
						sitem.cost:= sitem.cost + 10000 * r4;
						sitem.cost:= sitem.cost + 40000
						end;
					3, 8:
						begin
						sitem.flags:= (sitem.flags or $00080000);
						sitem.name := sitem.name + ' (RF)';
						add_toac(8, 8, 1, indx, r4);
						sitem.cost:= sitem.cost + 10000 * r4;
						sitem.cost:= sitem.cost + 40000
						end;
					4, 9:
						begin
						sitem.flags:= (sitem.flags or $00200000);
						sitem.name := sitem.name + ' (RC)';
						add_toac(8, 8, 1, indx, r4);
						sitem.cost:= sitem.cost + 10000 * r4;
						sitem.cost:= sitem.cost + 40000
						end;
					5, 10:
						begin
						sitem.flags:= (sitem.flags or $02000000);
						sitem.name := sitem.name + ' (RL)';
						add_toac(8, 8, 1, indx, r4);
						sitem.cost:= sitem.cost + 10000 * r4;
						sitem.cost:= sitem.cost + 30000
						end;
					else
						;
					end;

			40: { Amulets }
				case sitem.subval of
					1, 2:
						begin
						add_p1(0, 2, 2, indx, r5);
						sitem.cost:= sitem.cost + 10000 * r5
						end;
					3:
						begin
						add_p1(8, 15, 15, indx, r5);
						sitem.cost:= sitem.cost + 10000 * r5
						end;
					5:
						begin
						add_toac(4, 4, 0, indx, r4);
						sitem.cost:= sitem.cost + 10000 * r4
						end;
					else
						;
					end;

			45: { Rings }
				case sitem.subval of
					1, 2, 3, 4: { Gain stat }
						begin
						add_p1(0, 2, 2, indx, r5);
						sitem.cost:= sitem.cost + 10000 * r5
						end;
					7: { Speed }
						begin
						add_p1(1, 2, 1, indx, r5);
						sitem.cost:= sitem.cost + 500000 * r5
						end;
					8: { Searching }
						begin
						add_p1(8, 15, 15, indx, r5);
						sitem.cost:= sitem.cost + 10000 * r5
						end;
					10, 13, 26: { Slow Digestion, Feather-Falling, See-Invis }
						begin
						add_toac(2, 2, 1, indx, r4);
						sitem.cost:= sitem.cost + 10000 * r4
						end;
					17, 18, 19: { Lordly Protection }
						begin
						add_toac(10, 8, 5, indx, r4);
						sitem.cost:= sitem.cost + 10000 * r4
						end;
					22: { Increase Damage }
						begin
						add_todam(3, 3, 3, indx, r2);
						sitem.cost:= sitem.cost + 10000 * r2
						end;
					23: { Increase To-hit }
						begin
						add_tohit(3, 3, 3, indx, r1);
						sitem.cost:= sitem.cost + 10000 * r1
						end;
					24: { Protection }
						begin
						add_toac(4, 4, 1, indx, r4);
						sitem.cost:= sitem.cost + 10000 * r4
						end;
					33: { Slaying }
						begin
						add_tohit(3, 3, 3, indx, r1);
						add_todam(3, 3, 3, indx, r2);
						sitem.cost:= sitem.cost + 10000 * r2 + 10000 * r1
						end;
					else
						;
					end;

			55: { Staves }
				case sitem.subval of
					1:
						begin
						add_p1_rods(32, 20, 12, indx, r5);
						sitem.cost:= sitem.cost + 5000 * r5
						end;
					2:
						begin
						add_p1_rods(14, 8, 6, indx, r5);
						sitem.cost:= sitem.cost + 5000 * r5
						end;
					3:
						begin
						add_p1_rods(11, 5, 6, indx, r5);
						sitem.cost:= sitem.cost + 5000 * r5
						end;
					4:
						begin
						add_p1_rods(32, 20, 12, indx, r5);
						sitem.cost:= sitem.cost + 5000 * r5
						end;
					5:
						begin
						add_p1_rods(21, 15, 6, indx, r5);
						sitem.cost:= sitem.cost + 5000 * r5
						end;
					6:
						begin
						add_p1_rods(9, 4, 5, indx, r5);
						sitem.cost:= sitem.cost + 5000 * r5
						end;
					7:
						begin
						add_p1_rods(8, 5, 3, indx, r5);
						sitem.cost:= sitem.cost + 5000 * r5
						end;
					8:
						begin
						add_p1_rods(4, 3, 1, indx, r5);
						sitem.cost:= sitem.cost + 5000 * r5
						end;
					9:
						begin
						add_p1_rods(4, 3, 1, indx, r5);
						sitem.cost:= sitem.cost + 5000 * r5
						end;
					10:
						begin
						add_p1_rods(4, 3, 1, indx, r5);
						sitem.cost:= sitem.cost + 5000 * r5
						end;
					11:
						begin
						add_p1_rods(11, 5, 6, indx, r5);
						sitem.cost:= sitem.cost + 5000 * r5
						end;
					13:
						begin
						add_p1_rods(11, 5, 6, indx, r5);
						sitem.cost:= sitem.cost + 5000 * r5
						end;
					14:
						begin
						add_p1_rods(11, 5, 6, indx, r5);
						sitem.cost:= sitem.cost + 5000 * r5
						end;
					16:
						begin
						add_p1_rods(22, 10, 12, indx, r5);
						sitem.cost:= sitem.cost + 5000 * r5
						end;
					17:
						begin
						add_p1_rods(7, 3, 4, indx, r5);
						sitem.cost:= sitem.cost + 5000 * r5
						end;
					19:
						begin
						add_p1_rods(11, 5, 6, indx, r5);
						sitem.cost:= sitem.cost + 5000 * r5
						end;
					20:
						begin
						add_p1_rods(7, 3, 4, indx, r5);
						sitem.cost:= sitem.cost + 5000 * r5
						end;
					21:
						begin
						add_p1_rods(22, 10, 12, indx, r5);
						sitem.cost:= sitem.cost + 5000 * r5
						end;
					22:
						begin
						add_p1_rods(7, 3, 4, indx, r5);
						sitem.cost:= sitem.cost + 5000 * r5
						end;
					23:
						begin
						add_p1_rods(7, 3, 4, indx, r5);
						sitem.cost:= sitem.cost + 5000 * r5
						end;
					24:
						begin
						add_p1_rods(7, 3, 1, indx, r5);
						sitem.cost:= sitem.cost + 5000 * r5
						end;
					else
						;
					end;

			65: { Wands }
				case sitem.subval of
					1:
						begin
						add_p1_rods(16, 10, 6, indx, r5);
						sitem.cost:= sitem.cost + 5000 * r5
						end;
					2:
						begin
						add_p1_rods(14, 8, 6, indx, r5);
						sitem.cost:= sitem.cost + 5000 * r5
						end;
					3:
						begin
						add_p1_rods(11, 5, 6, indx, r5);
						sitem.cost:= sitem.cost + 5000 * r5
						end;
					4:
						begin
						add_p1_rods(14, 8, 6, indx, r5);
						sitem.cost:= sitem.cost + 5000 * r5
						end;
					5:
						begin
						add_p1_rods(7, 4, 3, indx, r5);
						sitem.cost:= sitem.cost + 5000 * r5
						end;
					6:
						begin
						add_p1_rods(14, 8, 6, indx, r5);
						sitem.cost:= sitem.cost + 5000 * r5
						end;
					9:
						begin
						add_p1_rods(16, 10, 6, indx, r5);
						sitem.cost:= sitem.cost + 5000 * r5
						end;
					10:
						begin
						add_p1_rods(18, 12, 6, indx, r5);
						sitem.cost:= sitem.cost + 5000 * r5
						end;
					11:
						begin
						add_p1_rods(22, 10, 12, indx, r5);
						sitem.cost:= sitem.cost + 5000 * r5
						end;
					12:
						begin
						add_p1_rods(6, 3, 3, indx, r5);
						sitem.cost:= sitem.cost + 5000 * r5
						end;
					13:
						begin
						add_p1_rods(14, 8, 6, indx, r5);
						sitem.cost:= sitem.cost + 5000 * r5
						end;
					14:
						begin
						add_p1_rods(16, 10, 6, indx, r5);
						sitem.cost:= sitem.cost + 5000 * r5
						end;
					15:
						begin
						add_p1_rods(8, 5, 3, indx, r5);
						sitem.cost:= sitem.cost + 5000 * r5
						end;
					16:
						begin
						add_p1_rods(8, 5, 3, indx, r5);
						sitem.cost:= sitem.cost + 5000 * r5
						end;
					17:
						begin
						add_p1_rods(11, 5, 6, indx, r5);
						sitem.cost:= sitem.cost + 5000 * r5
						end;
					18:
						begin
						add_p1_rods(9, 5, 4, indx, r5);
						sitem.cost:= sitem.cost + 5000 * r5
						end;
					19:
						begin
						add_p1_rods(12, 8, 4, indx, r5);
						sitem.cost:= sitem.cost + 5000 * r5
						end;
					20:
						begin
						add_p1_rods(12, 8, 4, indx, r5);
						sitem.cost:= sitem.cost + 5000 * r5
						end;
					21:
						begin
						add_p1_rods(12, 8, 4, indx, r5);
						sitem.cost:= sitem.cost + 5000 * r5
						end;
					22:
						begin
						add_p1_rods(36, 24, 12, indx, r5);
						sitem.cost:= sitem.cost + 5000 * r5
						end;
					23:
						begin
						add_p1_rods(12, 8, 4, indx, r5);
						sitem.cost:= sitem.cost + 5000 * r5
						end;
					24:
						begin
						add_p1_rods(16, 10, 6, indx, r5);
						sitem.cost:= sitem.cost + 5000 * r5
						end;
					else
						;
					end;
			else
				;
			end;

		scost:= -sitem.cost;
		insert_num(sitem.name, '%P1', sitem.p1, true);
		insert_num(sitem.name, '%P2', sitem.tohit, true);
		insert_num(sitem.name, '%P3', sitem.todam, true);
		insert_num(sitem.name, '%P4', sitem.toac, true);
		insert_num(sitem.name, '%P5', sitem.p1, false);
		insert_num(sitem.name, '%P6', sitem.ac, false);
		end;
	end;

//[psect(store$code)]
procedure store_carry(store_num: Integer; var ipos: Integer); forward;

{Add Black Market items to the inventory}
//[psect(store$code)]
procedure do_black_market;
	var
	indx,
	iptr,
	inven_num: Integer;

	begin
	inven_num:= 0;
	store[7].store_ctr:= 0;
	while (inven_num < store_inven_max) do
		inven_num:= 5 + randint(store_inven_max);

	if (inven_num > store_inven_max) then
		inven_num:= store_inven_max;

	for indx:= 1 to inven_num do
		with store[7].store_inven[indx] do
			begin
			iptr := randint(blk_mkt_max);
			sitem:= blk_mkt_init[iptr];
			soup_up_black_market(indx);
//			inventory[inven_max]:= sitem;
			store_carry(7, iptr);
			end;

	for indx:= inven_num to store_inven_max do
		with store[7].store_inven[indx] do
			sitem     := blank_treasure;

	store[7].store_ctr:= store[7].store_ctr - 1;
	end;


