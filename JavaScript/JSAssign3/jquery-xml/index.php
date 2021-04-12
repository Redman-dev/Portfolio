<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
	<head>
	<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
    <script type="text/javascript">
		$(document).ready(function(){
			$(".main").html('<form id="Form1" method="get" action="/index.php"></>');
			$.ajax({
				type: "GET",
				url: "form.xml",
				dataType: "xml",
				success: function(xml){
				$(xml).find('Field').each(function(){
				var sLabel = $(this).find('Label').text();
				var sDataType = $(this).find('DataType').text();
				var sFieldName = $(this).find('FieldName').text();
				var sInitialValue = $(this).find('InitialValue').text();
				if (sDataType == 'TextArea') {
					$('<label for="' + sFieldName + '">' + sLabel + '</label><br>' +
					'<textarea name="' + sFieldName + '" id="' +
					sFieldName + '">' + sInitialValue + '</textarea><br>').appendTo("#Form1");
				} else {
					$('<label for="' + sFieldName + '">' + sLabel + '</label><br>' +
					'<input type="' + sDataType + '" name="' + sFieldName + '" id="' +
					sFieldName + '" value="' + sInitialValue + '"></input><br>').appendTo("#Form1");
				}
				});
			},
			error: function() {
				alert("An error occurred while processing XML file.");
			}
			});
		});
	</script>
	</head>
	<body>
		<div class="main">
		</div>
	</body>
</html>
