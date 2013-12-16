#import <UIKit/UIKit.h>

#import "OCLint-Annotations.h"

@interface UIActivity (OCLintStaticChecks)
- (NSString *)activityType OCLINT_SUBCLASS_MUST_IMPLEMENT;
- (NSString *)activityTitle OCLINT_SUBCLASS_MUST_IMPLEMENT;
- (UIImage *)activityImage OCLINT_SUBCLASS_MUST_IMPLEMENT;
- (BOOL)canPerformWithActivityItems:(NSArray *)activityItems OCLINT_SUBCLASS_MUST_IMPLEMENT;
@end

@interface UICollectionViewController (OCLintStaticChecks)

- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section OCLINT_SUBCLASS_MUST_IMPLEMENT;
- (UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath OCLINT_SUBCLASS_MUST_IMPLEMENT;

@end

@interface UITableViewController (OCLintStaticChecks)

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section OCLINT_SUBCLASS_MUST_IMPLEMENT;
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath OCLINT_SUBCLASS_MUST_IMPLEMENT;

@end

@interface UIView (OCLintStaticChecks)

- (void)layoutSubviews OCLINT_MUST_CALL_SUPER;
- (void)updateConstraints OCLINT_MUST_CALL_SUPER;

@end

@interface UIViewController (OCLintStaticChecks)

- (void)setEditing:(BOOL)editing animated:(BOOL)animated OCLINT_MUST_CALL_SUPER;
- (void)viewWillAppear:(BOOL)animated OCLINT_MUST_CALL_SUPER;
- (void)viewDidAppear:(BOOL)animated OCLINT_MUST_CALL_SUPER;
- (void)viewWillDisappear:(BOOL)animated OCLINT_MUST_CALL_SUPER;
- (void)viewDidDisappear:(BOOL)animated OCLINT_MUST_CALL_SUPER;
- (void)viewWillLayoutSubviews OCLINT_MUST_CALL_SUPER;
- (void)viewDidLoad OCLINT_MUST_CALL_SUPER;

@end

@interface UIGestureRecognizer (OCLintStaticChecks)

- (void)canPreventGestureRecognizer OCLINT_MUST_CALL_SUPER;
- (void)canBePreventedByGestureRecognizer OCLINT_MUST_CALL_SUPER;
- (BOOL)shouldRequireFailureOfGestureRecognizer:(UIGestureRecognizer *)gesture OCLINT_MUST_CALL_SUPER;
- (BOOL)shouldBeRequiredToFailByGestureRecognizer:(UIGestureRecognizer *)gesture OCLINT_MUST_CALL_SUPER;
- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event OCLINT_MUST_CALL_SUPER;
- (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event OCLINT_MUST_CALL_SUPER;
- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event OCLINT_MUST_CALL_SUPER;
- (void)touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event OCLINT_MUST_CALL_SUPER;

@end
