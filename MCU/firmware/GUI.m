function GiaoDienVDK()
    % Tạo cửa sổ giao diện
    fig = uifigure('Name', 'Điều khiển VĐK - AI', 'Position', [200 200 350 200]);
    
    btnConn = uibutton(fig, 'Text', 'Kết nối', 'Position', [30 140 120 30], 'ButtonPushedFcn', @connect);
    btnDisconn = uibutton(fig, 'Text', 'Ngắt kết nối', 'Position', [200 140 120 30], 'ButtonPushedFcn', @disconnect);
    
    lblRaw = uilabel(fig, 'Text', 'Giá trị ADC thô: 0', 'Position', [30 90 250 30], 'FontSize', 14);
    lblVolt = uilabel(fig, 'Text', 'Điện áp: 0.00 V', 'Position', [30 40 250 30], 'FontSize', 14, 'FontWeight', 'bold');
    
    serial_obj = [];
    
    function connect(~, ~)
        try
            serial_obj = serialport("COM3", 9600); % ĐỔI COM3 THÀNH COM CỦA BẠN
            configureTerminator(serial_obj, "LF");
            configureCallback(serial_obj, "terminator", @readData);
            lblRaw.Text = 'Đã kết nối...';
        catch
            lblRaw.Text = 'Lỗi kết nối COM!';
        end
    end

    function disconnect(~, ~)
        if ~isempty(serial_obj)
            configureCallback(serial_obj, "off");
            clear serial_obj;
            lblRaw.Text = 'Đã ngắt kết nối.';
            lblVolt.Text = 'Điện áp: -- V';
        end
    end

    function readData(~, ~)
        try
            data = readline(serial_obj);
            parsed = sscanf(data, 'ADC: %d, VOLT: %f');
            if length(parsed) == 2
                lblRaw.Text = sprintf('Giá trị ADC thô: %d', parsed(1));
                lblVolt.Text = sprintf('Điện áp: %.2f V', parsed(2));
            end
        catch
        end
    end
end