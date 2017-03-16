/*****************************************************************************
 *                                                                           *
 * Module:       SRAM_Controller                                             *
 * Description:                                                              *
 *      This module is used for the sram controller for 3TB4 lab 4           *
 *                                                                           *
 *****************************************************************************/

module SRAM_Controller (
input           clk,       //done
input				 reset_n,   //done
input		[17:0]	address, //done
input				chipselect,  //chip_enable //done
input		[1:0]	byte_enable,
input				read,
input				write,
input		[15:0]	write_data,

// Bidirectionals
inout reg		[15:0]	SRAM_DQ,   //used for both reading and writing

// Outputs
output reg		[15:0]	read_data,

output		[17:0]	SRAM_ADDR, //done
output				SRAM_CE_N,   //done
output				SRAM_WE_N,   //done
output				SRAM_OE_N,   //done
output				SRAM_UB_N,   //done
output				SRAM_LB_N    //done
);

parameter [15:0] high_impedence = 16'bzzzzzzzzzzzzzzzz;
parameter [7:0] half_high_impedence = 8'bzzzzzzzz;
assign SRAM_ADDR = address; //Telling the SRAM that this is the address that we are interested in.
assign SRAM_CE_N = !(chipselect);
assign SRAM_WE_N = !(write);
assign SRAM_OE_N = !(read);
assign SRAM_UB_N = !(byte_enable[1]);
assign SRAM_LB_N = !(byte_enable[0]);
//SRAM_DQ = high_impedence;

integer x;
integer y;
// Add your code here

always @(posedge clk)
begin //0

if (chipselect == 1'b1)   //if chip select is ENABLED
begin //1
	if (read == 1'b0 && write == 1'b0)    //if you dont wanna read or write set I/O to HIGH-Z
	begin //2
		SRAM_DQ <= high_impedence;
	end  //2
	
	if (byte_enable[1] == 1'b0 && byte_enable[0] == 1'b0)   //if you want to read or write but dont want any of the bytes set I/O to HIGH-Z
	begin //3
		SRAM_DQ <= high_impedence;
	end //3
	
	if (read == 1'b1)
	begin //4
		case (byte_enable)
			2'b01 : begin    //when you want to only read the lower byte
						SRAM_DQ[15:8] <= half_high_impedence;
						read_data <= SRAM_DQ;
						end
						
			2'b10 : begin    //when you want to only read the higher byte
						SRAM_DQ[7:0] <= half_high_impedence;
						read_data <= SRAM_DQ;
						end
						
			2'b11 : begin   //when you want to read both bytes
					   read_data <= SRAM_DQ;
						end
		endcase
	end //4

	if (write == 1'b1)
	begin //5
		case (byte_enable)
			2'b01 : begin   //when you want to only write the lower byte
						SRAM_DQ <= write_data;
						SRAM_DQ[15:8] <= half_high_impedence;
						end
						
			2'b10 : begin   //when you want to only write the higher byte
						SRAM_DQ <= write_data;
						SRAM_DQ[7:0] <= half_high_impedence;
						end
						
			2'b11 : begin   //when you want to write both bytes
						SRAM_DQ <= write_data;
						end
		endcase
	end //5

end //1

else if (chipselect == 1'b0)    // NOT SELECTED MODE
	begin  //6     // if chip select is off 
	SRAM_DQ <= high_impedence;    //I/O line is HIGH-Z
	end //6

end //0 end always block
endmodule

