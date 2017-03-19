function result = butterworth( img,type )
%BUTTERWORTH butterworth�˲���ʵ��
%   ��img����butterworth��ͨ/��ͨ�˲������ش�����ͼ��
    % ���ٸ���Ҷ�任
    g = fft2(double(img));
    % ת�����ݾ���fftshift�����Ƶ��ģ���FFT��DC�����Ƶ�Ƶ�����ļ���Ƶ���ͼ��
    g = fftshift(g);
    [M,N]=size(g);
    result = zeros(M,N);
    prompt = {'Please enter D0:','Please enter n:'};
    if strcmp(type,'lowp')
        param = inputdlg(prompt,'Butterworth',1,{'10','1'},'on');
    else param = inputdlg(prompt,'Butterworth',1,{'4.5','2'},'on');
    end
    D0 = str2double(param{1,1});
    n = str2double(param{2,1});
    % ������ԭ������Ͻ��ƶ�������
    x0 = fix(M/2);
    y0 = fix(N/2);
    for x = 1:M
        for y = 1:N
            d = sqrt((x-x0)^2+(y-y0)^2);
            if strcmp(type,'lowp')
                % ��ͨ��ʽh(x,y) = 1/(1+(sqrt(x^2+y^2)/D0)^2n)
                h = 1/(1+(d/D0)^(2*n));
            elseif strcmp(type,'highp')
                % ��ͨ��ʽh(x,y) = 1/(1+(D0/sqrt(x^2+y^2))^2n)
                if d == 0
                    h = 0;
                else
                    h = 1/(1+(D0/d)^(2*n));
                end
            else h = 1;
            end
            result(x,y) = h * g(x,y);
        end
    end
    % �������Ƶ���DC�����Ƶ�ԭʼλ��
    result = ifftshift(result);
    % ���ٸ���Ҷ��任
    result = ifft2(result);
    result = uint8(real(result));
end

