<?php
session_start();
if(file_exists('main.output.win')) {
	$fp = fopen('main.output.win', 'r');
	$lines = array();
	while(!feof($fp)) {
		$lines[] = fgets($fp);
	}
	fclose($fp);
	if($_SESSION['line'] == "none") {
		for($i = 0; $i < count($lines); $i++) {
			print $lines[$i];
		}
		$_SESSION['line'] = $lines[count($lines) - 2];
	} else {
		$i = 0;
		while($_SESSION['line'] != $lines[$i]) {
			$i++;
		}
		$i++;
		for(; $i < count($lines); $i++) {
			print $lines[$i];
		}
		$_SESSION['line'] = $lines[count($lines) - 2];
	}
} else {
	print "QUIT";
	$_SESSION['line'] = "none";
}
?>
