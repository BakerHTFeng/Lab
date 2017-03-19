function result = myfft2( img )
%MYFFT2 ��ά���ٸ���Ҷ�任
%   ��M=N=2^nʱ�����ݹ�ʽ���ټ����ά����Ҷ�任�Ľ��
    [x,y] = size(img);
    result = zeros(x,y);
    % ��ά����Ҷ�任�൱����x��y�Ϸֱ����һ��һά����Ҷ�任
    for i=1:x;
        result(i,:) = myfft(img(i,:));
    end
    for j=1:y;
        result(:,j) = myfft(result(:,j));
    end
end
