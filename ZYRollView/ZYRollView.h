//
//  ZYRollView.h
//  ZYRollView
//
//  Created by XUZY
//  Copyright © https://github.com/xuzeyu/ZYRollView.git. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 默认cell样式 WSLItemID
 */
@interface ZYRollViewCell : UICollectionViewCell
@end

@class ZYRollView;

//代理协议
@protocol ZYRollViewDelegate <NSObject>
@optional
/**
 返回itemSize 默认值是CGSizeMake(self.frame.size.width, self.frame.size.height);
 */
- (CGSize)rollView:(ZYRollView *_Nonnull)rollView sizeForItemAtIndex:(NSInteger)index;
/**
 item的间隔 默认值0
 */
- (CGFloat)spaceOfItemInRollView:(ZYRollView *_Nonnull)rollView;
/**
 内边距 上 左 下 右 默认值UIEdgeInsetsMake(0, 0, 0, 0)
 */
- (UIEdgeInsets)paddingOfRollView:(ZYRollView *_Nonnull)rollView;
/**
 点击事件
 */
- (void)rollView:(ZYRollView *_Nonnull)rollView didSelectItemAtIndex:(NSInteger)index;
/**
 翻页完成的回调 只针对于分页效果
 */
- (void)rollView:(ZYRollView *_Nonnull)rollView didRollItemToIndex:(NSInteger)currentIndex;
/**
 自定义item样式
 */
- (ZYRollViewCell *_Nonnull)rollView:(ZYRollView *_Nonnull)rollView cellForItemAtIndex:(NSInteger )index;
@end

/**
 滚动样式
 */
typedef NS_ENUM(NSInteger, ZYRollViewScrollStyle) {
    ZYRollViewScrollStylePage = 0, /** 分页 必须等宽或高*/
    ZYRollViewScrollStyleStep   /** 渐进 可以不等宽或高*/
};

@interface ZYRollView : UIView

/**
 原始数据源
 */
@property (nonatomic, strong, nullable) NSMutableArray * sourceArray;

/**
 是否循环轮播 默认YES 如果NO，则自动禁止计时器
 */
@property (nonatomic, assign) BOOL loopEnabled;
/**
 是否允许滑动 默认YES
 */
@property (nonatomic, assign) BOOL scrollEnabled;
/**
 轮播方向 默认是 UICollectionViewScrollDirectionHorizontal 水平
 */
@property (nonatomic, assign) UICollectionViewScrollDirection scrollDirection;
/**
 轮播样式 默认是 ZYRollViewScrollStylePage 分页
 */
@property (nonatomic, assign) ZYRollViewScrollStyle scrollStyle;
/**
 设置初始化时的位置页码，默认为0 只对分页效果有效
 */
@property (nonatomic, assign) NSInteger startingPosition;

/**
 渐进轮播速率 单位是Point/s，以坐标系单位为准 默认60/s 如果为0 表示禁止计时器
 */
@property (nonatomic, assign) CGFloat speed;
/**
 分页轮播间隔时长 单位是s  默认3s 如果为0 表示禁止计时器
 */
@property (nonatomic, assign) CGFloat interval;

/**
 item的间隔 默认值0
 */
@property (nonatomic, assign) CGFloat spaceOfItem;

/**
 内边距 上 左 下 右 默认值UIEdgeInsetsMake(0, 0, 0, 0)
 */
@property (nonatomic, assign) UIEdgeInsets padding;

/** delegate*/
@property (nonatomic, weak) id<ZYRollViewDelegate> _Nullable delegate;

/**
 初始化方法 direction 滚动方向
 */
- (instancetype _Nonnull )initWithFrame:(CGRect)frame scrollDirection:(UICollectionViewScrollDirection)direction;

/**
 注册item样式 用法和UICollectionView相似
 */
- (void)registerClass:(nullable Class)cellClass forCellWithReuseIdentifier:(NSString *_Nonnull)identifier;
/**
 注册item样式 用法和UICollectionView相似
 */
- (void)registerNib:(nullable UINib *)nib forCellWithReuseIdentifier:(NSString *_Nonnull)identifier;
/**
 用于初始化ZYRollViewCell，自定义cell样式 用法和UICollectionView相似
 */
- (ZYRollViewCell *_Nullable)dequeueReusableCellWithReuseIdentifier:(NSString *_Nonnull)identifier forIndex:(NSInteger)index;
//返回索引为index的cell
- (ZYRollViewCell *_Nullable)cellForItemAtIndexPath:(NSInteger)index;

/**
 刷新数据源
 */
- (void)reloadData;
/**
 暂停自动轮播
 */
- (void)pause;
/**
 继续自动轮播
 */
- (void)play;

@end
