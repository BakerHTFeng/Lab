function result = edgdet( img,type )
%EDGDET ���ֱ�Ե������ӵ�ʵ��
%   �˴���ʾ��ϸ˵��
    [x,y] = size(img);
    result = zeros(x,y);
    % marr�����Ƕ���΢�����ӣ���˵�������
    if(strcmp(type,'marr'))
        % ����9x9����׼��Ϊ0.4�ĸ�˹ģ��
        temp = LoG(7, 1);
        G = myfilter(double(img),temp);
        result = G;
        [m,n]=size(img);
        % �������㣬�����ֵͬʱ����40�Ļ����϶���Ϊ��Ե
        for i=2:m-1
            for j=2:n-1
                m1 = result(i-1:i,j-1:j);
                m2 = result(i-1:i,j:j+1);
                m3 = result(i:i+1,j-1:j);
                m4 = result(i:i+1,j:j+1);
                tmp = [sum(m1(:)) sum(m2(:)) sum(m3(:)) sum(m4(:))];
                if max(tmp)>0 && min(tmp)<0 && abs(result(i,j)) > 40
                    result(i,j)=255;
                else
                    result(i,j)=0;
                end
            end
        end
    else
        % ����һ���ݶ�����
        switch type
            % sobel����ʵ��
            case 'sobel'
                % tempxΪx�����ݶ�ģ�壬tempyΪy�������ģ��
                tempx = [-1 -sqrt(2) -1; 0 0 0; 1 sqrt(2) 1];
                tempy = tempx';
                Gx = myfilter(double(img),tempx);
                Gy = myfilter(double(img),tempy);
                % ģ��ļ�Ȩ����
                G = sqrt(Gx.^2 + Gy.^2);
                % �������䷽�����ֵ
                thresh = 0.5*(max(G(:)) - max(img(:)));
            % prewitt����ʵ��
            case 'prewitt'
                % tempxΪx�����ݶ�ģ�壬tempyΪy�������ģ��
                tempx = [-1 -1 -1; 0 0 0; 1 1 1];
                tempy = tempx';
                Gx = myfilter(double(img),tempx);
                Gy = myfilter(double(img),tempy);
                % ģ��ļ�Ȩ����
                G = abs(Gx) + abs(Gy);
                % �������䷽�����ֵ
                thresh = 0.5*(max(G(:)) - max(img(:)));
            % roberts����ʵ��
            case 'roberts'
                % tempxΪx�����ݶ�ģ�壬tempyΪy�������ģ��
                tempx = [1 0; 0 -1];
                tempy = [0 1; -1 0];
                Gx = myfilter(double(img),tempx);
                Gy = myfilter(double(img),tempy);
                % ģ��ļ�Ȩ����
                G = abs(Gx) + abs(Gy);
                % �������䷽�����ֵ
                thresh = 0.5*(max(G(:)) - max(img(:)));
        end
         % ������ֵ���Ҷȶ�ֵ��
        for i = 1:x
            for j = 1:y
                if G(i,j) >= thresh
                    result(i,j) = 255;
                else result(i,j) = 0;
                end
            end
        end    
    end
end

function result = myfilter( img, temp )
%MYFILTER �˲�����
%   ��img����tempģ����˲�����
    % ģ����ת180�ȣ����������ת��Ϊ�������
    temp = rot90(temp,2);
    % ���������
    result = conv2(img,temp,'same');
end
