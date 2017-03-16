module lab4 (
input				CLOCK_50,
input		[0:0]	KEY,

// Bidirectionals
inout		[15:0]	SRAM_DQ,

// Outputs

output		[17:0]	SRAM_ADDR,

output				SRAM_CE_N,
output				SRAM_WE_N,
output				SRAM_OE_N,
output				SRAM_UB_N,
output				SRAM_LB_N

);


// Internal Wires
wire [31:0] address;
wire bus_enable;
wire [1:0] byte_enable;
wire rw;
wire [15:0] write_data;

wire acknowledge;
wire [15:0]read_data;

// The following dummy wires are there just to ensure that 
// Quartus does not perform certain optimizations, which may
// result in these signals appearing inverted when observed in SignalTap II
// The key to this is the /*synthesis keep */ comment, which actually
// has a meaning to Quartus. It is important that the comment appear before the semicolon
// This comment does not affect functionality in any significant way
wire				SRAM_CE_N_wire /*synthesis keep */;
wire				SRAM_WE_N_wire /*synthesis keep */;
wire				SRAM_OE_N_wire /*synthesis keep */;
wire				SRAM_UB_N_wire /*synthesis keep */;
wire				SRAM_LB_N_wire /*synthesis keep */;


assign SRAM_CE_N = SRAM_CE_N_wire;
assign SRAM_WE_N = SRAM_WE_N_wire;
assign SRAM_OE_N = SRAM_OE_N_wire;
assign SRAM_UB_N = SRAM_UB_N_wire;
assign SRAM_LB_N = SRAM_LB_N_wire;

sopc_system  NiosII(
		//Inputs
		.clk_clk(CLOCK_50),     // clk.clk
		.reset_reset_n(KEY[0]), //reset.reset_n
		.sram_controller_0_conduit_end_export(SRAM_DQ),  
		.sram_controller_0_conduit_end_1_export(SRAM_ADDR), 
		.sram_controller_0_conduit_end_2_export(SRAM_CE_N_wire), 
		.sram_controller_0_conduit_end_3_export(SRAM_WE_N_wire), 
		.sram_controller_0_conduit_end_4_export(SRAM_OE_N_wire), 
		.sram_controller_0_conduit_end_5_export(SRAM_UB_N_wire), 
		.sram_controller_0_conduit_end_6_export(SRAM_LB_N_wire));


endmodule

